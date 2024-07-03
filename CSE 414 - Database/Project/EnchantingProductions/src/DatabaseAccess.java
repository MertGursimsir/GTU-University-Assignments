import javafx.application.Application;
import javafx.collections.ObservableList;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.*;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.collections.FXCollections;

import java.sql.*;
import java.util.*;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import java.math.BigDecimal;
import java.time.*;



public class DatabaseAccess extends Application {

    private Connection connection;
    private ComboBox<String> roleBox;
    private TextField emailInput;
    private PasswordField passwordInput;
    private Button loginButton;

    @Override
    public void start(Stage primaryStage) {
        connectDatabase();

        primaryStage.setTitle("Enchanting Productions");

        primaryStage.getIcons().add(new Image("file:resources/icon.jpg"));

        VBox mainLayout = new VBox();
        mainLayout.setPadding(new Insets(10, 10, 10, 10));
        mainLayout.setSpacing(10);

        ImageView imageView = new ImageView(new Image("file:resources/theatre.png"));
        imageView.setFitWidth(575);
        imageView.setPreserveRatio(true);

        Label titleLabel = new Label("Enchanting Productions");
        titleLabel.setStyle("-fx-font-size: 24px; -fx-text-fill: #ffffff; -fx-alignment: center; -fx-font-style: italic; -fx-font-weight: bold;");
        VBox titleBox = new VBox(titleLabel);
        titleBox.setPadding(new Insets(10));
        titleBox.setStyle("-fx-alignment: center;");

        GridPane grid = new GridPane();
        grid.setPadding(new Insets(10, 10, 10, 10));
        grid.setVgap(8);
        grid.setHgap(10);
        grid.setStyle("-fx-background-color: rgba(255, 255, 255, 0.8); -fx-padding: 20; -fx-border-radius: 10; -fx-background-radius: 10;");

        Label roleLabel = new Label("Select Role:");
        roleLabel.setStyle("-fx-text-fill: #000000;");
        GridPane.setConstraints(roleLabel, 0, 0);
        roleBox = new ComboBox<>();
        roleBox.getItems().addAll("Audience", "Director", "Manager");
        GridPane.setConstraints(roleBox, 1, 0);

        Label emailLabel = new Label("Email:");
        emailLabel.setStyle("-fx-text-fill: #000000;");
        GridPane.setConstraints(emailLabel, 0, 1);
        emailInput = new TextField();
        GridPane.setConstraints(emailInput, 1, 1);

        Label passwordLabel = new Label("Password:");
        passwordLabel.setStyle("-fx-text-fill: #000000;");
        GridPane.setConstraints(passwordLabel, 0, 2);
        passwordInput = new PasswordField();
        GridPane.setConstraints(passwordInput, 1, 2);

        loginButton = new Button("Login");
        GridPane.setConstraints(loginButton, 1, 3);
        loginButton.setOnAction(e -> loginUser());

        Button enrollButton = new Button("Enroll");
        GridPane.setConstraints(enrollButton, 1, 4);
        enrollButton.setOnAction(e -> openEnrollmentPage());

        grid.getChildren().addAll(roleLabel, roleBox, emailLabel, emailInput, passwordLabel, passwordInput, loginButton, enrollButton);

        mainLayout.getChildren().addAll(imageView, titleBox, grid);

        Scene scene = new Scene(mainLayout, 600, 700);
        scene.getStylesheets().add("file:resources/styles.css");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void connectDatabase() {
        try {
            String url = "jdbc:postgresql://localhost:5432/EnchantingProductions";
            String user = "postgres";
            String password = "admin";
            connection = DriverManager.getConnection(url, user, password);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void loginUser() {
        String role = roleBox.getValue();
        String email = emailInput.getText();
        String password = passwordInput.getText();

        if (role == null || email.isEmpty() || password.isEmpty()) {
            showErrorPopup("Please fill in all fields.");
            return;
        }

        try {
            String sql;
            if (role.equalsIgnoreCase("audience")) {
                sql = "SELECT a.password FROM Audience a " +
                        "JOIN Person p ON a.person_id = p.person_id " +
                        "WHERE p.email = ?";
            } else if (role.equalsIgnoreCase("manager")) {
                sql = "SELECT m.password FROM Manager m " +
                        "JOIN Person p ON m.person_id = p.person_id " +
                        "WHERE p.email = ?";
            } else if (role.equalsIgnoreCase("director")) {
                sql = "SELECT d.password FROM Director d " +
                        "JOIN Person p ON d.person_id = p.person_id " +
                        "WHERE p.email = ?";
            } else {
                showErrorPopup("Invalid role selected.");
                return;
            }

            PreparedStatement stmt = connection.prepareStatement(sql);
            stmt.setString(1, email);
            ResultSet rs = stmt.executeQuery();

            if (rs.next()) {
                String storedHashedPassword = rs.getString("password");
                String inputHashedPassword = hashPassword(password);
                if (storedHashedPassword.equals(inputHashedPassword)) {
                    showSuccessPopup("Login successful.");
                    if (role.equalsIgnoreCase("audience")) {
                        setDatabaseRole("audience");
                        openAudiencePage(email);
                    } else if (role.equalsIgnoreCase("manager")) {
                        setDatabaseRole("manager");
                        openManagerDashboard(email);
                    } else if (role.equalsIgnoreCase("director")) {
                        setDatabaseRole("director");
                        openDirectorPage(email);
                    }
                } else {
                    showErrorPopup("Invalid email or password.");
                }
            } else {
                showErrorPopup("Invalid email or password.");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void setDatabaseRole(String role) {
        try {
            Statement stmt = connection.createStatement();
            stmt.executeUpdate("SET ROLE " + role);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void openEnrollmentPage() {
        Stage enrollmentStage = new Stage();
        enrollmentStage.initModality(Modality.APPLICATION_MODAL);
        enrollmentStage.setTitle("User Enrollment");

        enrollmentStage.getIcons().add(new Image("file:resources/icon.jpg"));

        VBox layout = new VBox(10);
        layout.setPadding(new Insets(10));
        layout.setSpacing(10);

        Label roleLabel = new Label("Select Role:");
        ComboBox<String> roleBox = new ComboBox<>();
        roleBox.getItems().addAll("Audience", "Director");

        Label nameLabel = new Label("Name:");
        TextField nameInput = new TextField();

        Label emailLabel = new Label("Email:");
        TextField emailInput = new TextField();

        Label passwordLabel = new Label("Password:");
        PasswordField passwordInput = new PasswordField();

        Label phoneLabel = new Label("Phone:");
        TextField phoneInput = new TextField();

        Button enrollButton = new Button("Enroll");
        enrollButton.setOnAction(e -> {
            String role = roleBox.getValue();
            if (role == null || emailInput.getText().isEmpty() || nameInput.getText().isEmpty() || passwordInput.getText().isEmpty() || (role.equals("Audience") && phoneInput.getText().isEmpty())) {
                showErrorPopup("Please fill in all fields.");
                return;
            }
            if (role.equals("Audience")) {
                enrollAudience(nameInput.getText(), emailInput.getText(), phoneInput.getText(), passwordInput.getText());
            } else if (role.equals("Director")) {
                enrollDirector(nameInput.getText(), emailInput.getText(), passwordInput.getText());
            }
            enrollmentStage.close();
        });

        layout.getChildren().addAll(roleLabel, roleBox, nameLabel, nameInput, emailLabel, emailInput, passwordLabel, passwordInput, phoneLabel, phoneInput, enrollButton);

        Scene scene = new Scene(layout, 400, 400);
        scene.getStylesheets().add("file:resources/styles.css");
        enrollmentStage.setScene(scene);
        enrollmentStage.show();
    }

    private void enrollDirector(String name, String email, String password) {
        if (email.isEmpty() || name.isEmpty() || password.isEmpty()) {
            showErrorPopup("Empty inputs.");
            return;
        }

        try {
            PreparedStatement checkEmailStmt = connection.prepareStatement(
                    "SELECT COUNT(*) FROM Director d JOIN Person p ON d.person_id = p.person_id WHERE p.email = ?");
            checkEmailStmt.setString(1, email);
            ResultSet rs = checkEmailStmt.executeQuery();
            if (rs.next() && rs.getInt(1) > 0) {
                showErrorPopup("This email is already registered as a director.");
                return;
            }

            connection.setAutoCommit(false);

            PreparedStatement personStmt = connection.prepareStatement(
                    "INSERT INTO Person (email, phone) VALUES (?, ?) RETURNING person_id");
            personStmt.setString(1, email);
            personStmt.setString(2, "");
            ResultSet personRs = personStmt.executeQuery();
            int personId = 0;
            if (personRs.next()) {
                personId = personRs.getInt("person_id");
            }

            PreparedStatement detailsStmt = connection.prepareStatement(
                    "INSERT INTO PersonDetails (email, name) VALUES (?, ?)");
            detailsStmt.setString(1, email);
            detailsStmt.setString(2, name);
            detailsStmt.executeUpdate();

            String hashedPassword = hashPassword(password);


            PreparedStatement directorStmt = connection.prepareStatement(
                    "INSERT INTO Director (person_id, password) VALUES (?, ?)");
            directorStmt.setInt(1, personId);
            directorStmt.setString(2, hashedPassword);
            directorStmt.executeUpdate();

            connection.commit();
            showSuccessPopup("You have successfully enrolled\nas a Director.");
        } catch (SQLException e) {
            e.printStackTrace();
            try {
                connection.rollback();
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }



    private void enrollAudience(String name, String email, String phone, String password) {
        if (email.isEmpty() || name.isEmpty() || phone.isEmpty() || password.isEmpty()) {
            showErrorPopup("Empty inputs.");
            return;
        }

        try {
            PreparedStatement checkEmailStmt = connection.prepareStatement(
                    "SELECT COUNT(*) FROM Audience a JOIN Person p ON a.person_id = p.person_id WHERE p.email = ?");
            checkEmailStmt.setString(1, email);
            ResultSet rs = checkEmailStmt.executeQuery();
            if (rs.next() && rs.getInt(1) > 0) {
                showErrorPopup("This email is already registered as an audience.");
                return;
            }

            connection.setAutoCommit(false);

            PreparedStatement personStmt = connection.prepareStatement(
                    "INSERT INTO Person (email, phone) VALUES (?, ?) RETURNING person_id");
            personStmt.setString(1, email);
            personStmt.setString(2, phone);
            ResultSet personRs = personStmt.executeQuery();
            int personId = 0;
            if (personRs.next()) {
                personId = personRs.getInt("person_id");
            }

            PreparedStatement detailsStmt = connection.prepareStatement(
                    "INSERT INTO PersonDetails (email, name) VALUES (?, ?)");
            detailsStmt.setString(1, email);
            detailsStmt.setString(2, name);
            detailsStmt.executeUpdate();

            String hashedPassword = hashPassword(password);

            PreparedStatement audienceStmt = connection.prepareStatement(
                    "INSERT INTO Audience (person_id, password, membership_level) VALUES (?, ?, ?)");
            audienceStmt.setInt(1, personId);
            audienceStmt.setString(2, hashedPassword);
            audienceStmt.setString(3, "Basic");
            audienceStmt.executeUpdate();

            connection.commit();
            showSuccessPopup("You have successfully enrolled\nas an Audience.");
        } catch (SQLException e) {
            e.printStackTrace();
            try {
                connection.rollback();
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }

    private void insertProduction(String email, String title, String genre, String synopsis, LocalDate startDate, LocalDate endDate, String budget, ObservableList<String> castMembersList) {
        if (title.isEmpty() || genre.isEmpty() || synopsis.isEmpty() || startDate == null || endDate == null || budget.isEmpty()) {
            showErrorPopup("All fields must be filled out.");
            return;
        }

        if (castMembersList.isEmpty()) {
            showErrorPopup("Please add at least one cast member before inserting the production.");
            return;
        }

        if (isTitleDuplicate(title)) {
            showErrorPopup("The title of the production already exists.\nPlease choose a different title.");
            return;
        }

        try {
            connection.setAutoCommit(false);

            PreparedStatement insertProductionStmt = connection.prepareStatement(
                    "INSERT INTO Production (title, start_date, end_date, budget) VALUES (?, ?, ?, ?) RETURNING production_id");
            insertProductionStmt.setString(1, title);
            insertProductionStmt.setDate(2, java.sql.Date.valueOf(startDate));
            insertProductionStmt.setDate(3, java.sql.Date.valueOf(endDate));
            insertProductionStmt.setBigDecimal(4, new BigDecimal(budget));
            ResultSet productionRs = insertProductionStmt.executeQuery();
            int productionId = 0;
            if (productionRs.next()) {
                productionId = productionRs.getInt("production_id");
            }

            PreparedStatement insertProductionDetailsStmt = connection.prepareStatement(
                    "INSERT INTO ProductionDetails (title, genre, synopsis) VALUES (?, ?, ?)");
            insertProductionDetailsStmt.setString(1, title);
            insertProductionDetailsStmt.setString(2, genre);
            insertProductionDetailsStmt.setString(3, synopsis);
            insertProductionDetailsStmt.executeUpdate();

            PreparedStatement getDirectorStmt = connection.prepareStatement(
                    "SELECT d.person_id FROM Director d JOIN Person p ON d.person_id = p.person_id WHERE p.email = ?");
            getDirectorStmt.setString(1, email);
            ResultSet directorRs = getDirectorStmt.executeQuery();
            int directorId = 0;
            if (directorRs.next()) {
                directorId = directorRs.getInt("person_id");
            }

            PreparedStatement insertProductionDirectorStmt = connection.prepareStatement(
                    "INSERT INTO ProductionDirector (production_id, person_id) VALUES (?, ?)");
            insertProductionDirectorStmt.setInt(1, productionId);
            insertProductionDirectorStmt.setInt(2, directorId);
            insertProductionDirectorStmt.executeUpdate();

            for (String castMember : castMembersList) {
                String[] parts = castMember.split(" as ");
                String castEmail = parts[0];
                String role = parts[1];

                PreparedStatement getCastStmt = connection.prepareStatement("SELECT person_id FROM Person WHERE email = ?");
                getCastStmt.setString(1, castEmail);
                ResultSet castRs = getCastStmt.executeQuery();
                int personId = 0;
                if (castRs.next()) {
                    personId = castRs.getInt("person_id");
                }

                PreparedStatement insertProductionCastStmt = connection.prepareStatement("INSERT INTO ProductionCast (production_id, person_id, role) VALUES (?, ?, ?)");
                insertProductionCastStmt.setInt(1, productionId);
                insertProductionCastStmt.setInt(2, personId);
                insertProductionCastStmt.setString(3, role);
                insertProductionCastStmt.executeUpdate();
            }

            connection.commit();
            showSuccessPopup("Production and cast members added \nsuccessfully.");
        } catch (SQLException e) {
            e.printStackTrace();
            try {
                connection.rollback();
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }

    private boolean isTitleDuplicate(String title) {
        try {
            PreparedStatement stmt = connection.prepareStatement("SELECT COUNT(*) FROM Production WHERE title = ?");
            stmt.setString(1, title);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return rs.getInt(1) > 0;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
    }



    private void resetDatabaseRole() {
        try {
            Statement stmt = connection.createStatement();
            stmt.executeUpdate("RESET ROLE");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void openManagerDashboard(String email) {
        Stage managerStage = new Stage();
        managerStage.initModality(Modality.APPLICATION_MODAL);
        managerStage.setTitle("Manager Dashboard");

        managerStage.getIcons().add(new Image("file:resources/icon.jpg"));

        VBox layout = new VBox(10);
        layout.setPadding(new Insets(10));
        layout.setSpacing(10);

        ImageView imageView = new ImageView(new Image("file:resources/manager.jpg"));
        imageView.setFitWidth(600);
        imageView.setPreserveRatio(true);
        imageView.setSmooth(true);
        imageView.setCache(true);

        Label titleLabel = new Label("Manager Dashboard");
        titleLabel.setStyle("-fx-font-size: 24px; -fx-text-fill: #ffffff; -fx-alignment: center; -fx-font-style: italic; -fx-font-weight: bold;");
        titleLabel.setPadding(new Insets(10, 0, 20, 0));

        Label productionLabel = new Label("Select Production:");
        ComboBox<String> productionBox = new ComboBox<>();
        List<String> productions = getProductionsNotPerformedAtManagerVenue(email);
        productionBox.getItems().addAll(productions);

        Button infoButton = new Button("Production Info");
        infoButton.setMaxWidth(575);
        infoButton.setOnAction(e -> showProductionInfo(productionBox.getValue()));

        Label performanceLabel = new Label("Add Performance:");
        DatePicker dateInput = new DatePicker();
        dateInput.setPromptText("Date");

        TextField timeInput = new TextField();
        timeInput.setPromptText("Time (HH:MM)");

        TextField ticketsInput = new TextField();
        ticketsInput.setPromptText("Number of Tickets");

        Button addPerformanceButton = new Button("Add Performance");
        addPerformanceButton.setMaxWidth(575);
        addPerformanceButton.setOnAction(e -> addPerformanceForProduction(productionBox.getValue(), dateInput.getValue(), timeInput.getText(), ticketsInput.getText(), email, productionBox));

        Button viewLogsButton = new Button("View Production Logs");
        viewLogsButton.setMaxWidth(575);
        viewLogsButton.setOnAction(e -> showProductionLogs());

        layout.getChildren().addAll(imageView, titleLabel, productionLabel, productionBox, infoButton, viewLogsButton, performanceLabel, dateInput, timeInput, ticketsInput, addPerformanceButton);

        Scene scene = new Scene(layout, 600, 820);
        scene.getStylesheets().add("file:resources/styles.css");
        managerStage.setScene(scene);

        managerStage.setOnCloseRequest(event -> {
            resetDatabaseRole();
        });

        managerStage.show();
    }

    private void showProductionLogs() {
        Stage logStage = new Stage();
        logStage.initModality(Modality.APPLICATION_MODAL);
        logStage.setTitle("Production Logs");

        logStage.getIcons().add(new Image("file:resources/icon.jpg"));

        TextArea logArea = new TextArea();
        logArea.setEditable(false);
        logArea.setWrapText(true);
        logArea.setPrefHeight(500);
        logArea.setPrefWidth(800);

        StringBuilder logContent = new StringBuilder("Production Logs:\n\n");

        try {
            Statement stmt = connection.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM ProductionLog");

            while (rs.next()) {
                logContent.append("Production ID: ").append(rs.getInt("production_id")).append("\n")
                        .append("Director ID: ").append(rs.getInt("director_id")).append("\n")
                        .append("Title: ").append(rs.getString("title")).append("\n")
                        .append("Genre: ").append(rs.getString("genre")).append("\n")
                        .append("Synopsis: ").append(rs.getString("synopsis")).append("\n")
                        .append("Start Date: ").append(rs.getDate("start_date")).append("\n")
                        .append("End Date: ").append(rs.getDate("end_date")).append("\n")
                        .append("Budget: ").append(rs.getBigDecimal("budget")).append("\n")
                        .append("Log Time: ").append(rs.getTimestamp("log_time")).append("\n\n");
            }
        } catch (SQLException e) {
            e.printStackTrace();
            logContent.append("Error fetching logs: ").append(e.getMessage());
        }

        logArea.setText(logContent.toString());

        VBox layout = new VBox(10);
        layout.setPadding(new Insets(10));
        layout.getChildren().add(logArea);

        Scene scene = new Scene(layout, 820, 520);
        scene.getStylesheets().add("file:resources/styles.css");
        logStage.setScene(scene);
        logStage.show();
    }


    private List<String> getProductionsNotPerformedAtManagerVenue(String managerEmail) {
        List<String> productions = new ArrayList<>();
        try {
            PreparedStatement getVenueStmt = connection.prepareStatement(
                    "SELECT mv.venue_id FROM ManagerVenue mv JOIN Person p ON mv.person_id = p.person_id WHERE p.email = ?");
            getVenueStmt.setString(1, managerEmail);
            ResultSet venueRs = getVenueStmt.executeQuery();
            int venueId = 0;
            if (venueRs.next()) {
                venueId = venueRs.getInt("venue_id");
            }

            PreparedStatement stmt = connection.prepareStatement(
                    "SELECT DISTINCT pr.title FROM Production pr LEFT JOIN ProductionVenue pv ON pr.production_id = pv.production_id AND pv.venue_id = ? WHERE pv.venue_id IS NULL");
            stmt.setInt(1, venueId);
            ResultSet rs = stmt.executeQuery();
            while (rs.next()) {
                productions.add(rs.getString("title"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return productions;
    }





    private void addPerformanceForProduction(String productionTitle, LocalDate date, String time, String numTickets, String managerEmail, ComboBox<String> productionBox) {
        if (productionTitle == null || date == null || time.isEmpty() || numTickets.isEmpty()) {
            showErrorPopup("All fields must be filled out.");
            return;
        }

        if (!time.matches("^([01]?\\d|2[0-3]):[0-5]\\d$")) {
            showErrorPopup("Time must be in HH:MM format.");
            return;
        }

        try {
            LocalDateTime dateTime = LocalDateTime.of(date, LocalTime.parse(time));

            PreparedStatement getProductionStmt = connection.prepareStatement("SELECT pr.production_id FROM Production pr WHERE pr.title = ?");
            getProductionStmt.setString(1, productionTitle);
            ResultSet productionRs = getProductionStmt.executeQuery();
            int productionId = 0;
            if (productionRs.next()) {
                productionId = productionRs.getInt("production_id");
            }

            PreparedStatement getVenueStmt = connection.prepareStatement(
                    "SELECT mv.venue_id FROM ManagerVenue mv " +
                            "JOIN Person p ON mv.person_id = p.person_id " +
                            "WHERE p.email = ?");
            getVenueStmt.setString(1, managerEmail);
            ResultSet venueRs = getVenueStmt.executeQuery();
            int venueId = 0;
            if (venueRs.next()) {
                venueId = venueRs.getInt("venue_id");
            }

            PreparedStatement fetchProductionDatesStmt = connection.prepareStatement(
                    "SELECT start_date, end_date FROM Production WHERE production_id = ?");
            fetchProductionDatesStmt.setInt(1, productionId);
            ResultSet productionDatesRs = fetchProductionDatesStmt.executeQuery();

            LocalDate startDate = null;
            LocalDate endDate = null;
            if (productionDatesRs.next()) {
                startDate = productionDatesRs.getDate("start_date").toLocalDate();
                endDate = productionDatesRs.getDate("end_date").toLocalDate();
            }

            LocalDate performanceDate = dateTime.toLocalDate();
            if (performanceDate.isBefore(startDate) || performanceDate.isAfter(endDate)) {
                showErrorPopup("Performance date must be between " + startDate + "\nand " + endDate + ".");
                return;
            }

            connection.setAutoCommit(false);

            PreparedStatement insertPerformanceStmt = connection.prepareStatement(
                    "INSERT INTO Performance (date_and_time, number_of_tickets) VALUES (?, ?) RETURNING performance_id");
            insertPerformanceStmt.setTimestamp(1, Timestamp.valueOf(dateTime));
            insertPerformanceStmt.setInt(2, Integer.parseInt(numTickets));
            ResultSet performanceRs = insertPerformanceStmt.executeQuery();
            int performanceId = 0;
            if (performanceRs.next()) {
                performanceId = performanceRs.getInt("performance_id");
            }

            PreparedStatement insertPerformanceVenueStmt = connection.prepareStatement(
                    "INSERT INTO PerformanceVenue (performance_id, venue_id) VALUES (?, ?)");
            insertPerformanceVenueStmt.setInt(1, performanceId);
            insertPerformanceVenueStmt.setInt(2, venueId);
            insertPerformanceVenueStmt.executeUpdate();


            PreparedStatement checkPerformanceStmt = connection.prepareStatement(
                    "SELECT EXISTS (SELECT 1 FROM Performance WHERE performance_id = ?)");
            checkPerformanceStmt.setInt(1, performanceId);
            ResultSet rs = checkPerformanceStmt.executeQuery();
            if (!(rs.next() && rs.getBoolean(1))) {
                connection.rollback();
                showErrorPopup("There is already a performance at that time.");
                setDatabaseRole("manager");
                return;
            }

            PreparedStatement insertProductionVenueStmt = connection.prepareStatement(
                    "INSERT INTO ProductionVenue (production_id, venue_id) VALUES (?, ?)");
            insertProductionVenueStmt.setInt(1, productionId);
            insertProductionVenueStmt.setInt(2, venueId);
            insertProductionVenueStmt.executeUpdate();

            PreparedStatement insertProductionPerformanceStmt = connection.prepareStatement(
                    "INSERT INTO PerformanceProduction (performance_id, production_id) VALUES (?, ?)");
            insertProductionPerformanceStmt.setInt(1, performanceId);
            insertProductionPerformanceStmt.setInt(2, productionId);
            insertProductionPerformanceStmt.executeUpdate();

            connection.commit();

            showSuccessPopup("Performance added successfully.");
            productionBox.getItems().remove(productionTitle);
            productionBox.getSelectionModel().clearSelection();
        } catch (SQLException e) {
            showErrorPopup(e.getMessage());
            try {
                connection.rollback();
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }

    private void openDirectorPage(String email) {
        Stage directorStage = new Stage();
        directorStage.initModality(Modality.APPLICATION_MODAL);
        directorStage.setTitle("Director Dashboard");


        directorStage.getIcons().add(new Image("file:resources/icon.jpg"));

        VBox layout = new VBox(10);
        layout.setPadding(new Insets(10));
        layout.setSpacing(10);

        ImageView imageView = new ImageView(new Image("file:resources/director.jpg"));
        imageView.setFitWidth(575);
        imageView.setPreserveRatio(true);
        imageView.setSmooth(true);
        imageView.setCache(true);

        Label titleLabel = new Label("Director Dashboard");
        titleLabel.setStyle("-fx-font-size: 24px; -fx-text-fill: #ffffff; -fx-alignment: center; -fx-font-style: italic; -fx-font-weight: bold;");
        titleLabel.setPadding(new Insets(10, 0, 20, 0));

        Label newProductionLabel = new Label("Insert New Production:");
        TextField titleInput = new TextField();
        titleInput.setPromptText("Title");

        TextField genreInput = new TextField();
        genreInput.setPromptText("Genre");

        TextArea synopsisInput = new TextArea();
        synopsisInput.setPromptText("Synopsis");
        synopsisInput.setWrapText(true);

        DatePicker startDateInput = new DatePicker();
        startDateInput.setPromptText("Start Date");

        DatePicker endDateInput = new DatePicker();
        endDateInput.setPromptText("End Date");

        TextField budgetInput = new TextField();
        budgetInput.setPromptText("Budget");

        budgetInput.textProperty().addListener((observable, oldValue, newValue) -> {
            if (!newValue.matches("\\d*(\\.\\d*)?")) {
                budgetInput.setText(oldValue);
            }
        });

        Label castMembersLabel = new Label("Added Cast Members:");
        ListView<String> castMembersListView = new ListView<>();
        ObservableList<String> castMembersList = FXCollections.observableArrayList();
        castMembersListView.setItems(castMembersList);

        Button addCastButton = new Button("Add Cast Member");
        addCastButton.setMaxWidth(575);
        addCastButton.setOnAction(e -> openAddCastMemberScreen(titleInput.getText(), castMembersList));

        Button insertProductionButton = new Button("Insert Production");
        insertProductionButton.setMaxWidth(575);
        insertProductionButton.setOnAction(e -> {
            if (castMembersList.isEmpty()) {
                showErrorPopup("Please add at least one cast member before\ninserting the production.");
                return;
            }
            insertProduction(email, titleInput.getText(), genreInput.getText(), synopsisInput.getText(),
                    startDateInput.getValue(), endDateInput.getValue(), budgetInput.getText(), castMembersList);
        });

        layout.getChildren().addAll(imageView, titleLabel, newProductionLabel, titleInput, genreInput, synopsisInput, startDateInput, endDateInput, budgetInput, castMembersLabel, castMembersListView, addCastButton, insertProductionButton);

        Scene scene = new Scene(layout, 600, 950);
        scene.getStylesheets().add("file:resources/styles.css");
        directorStage.setScene(scene);

        directorStage.setOnCloseRequest(event -> {
            resetDatabaseRole();
        });

        directorStage.show();
    }


    private void openAddCastMemberScreen(String productionTitle, ObservableList<String> castMembersList) {
        if (productionTitle.isEmpty()) {
            showErrorPopup("Please enter the production title first.");
            return;
        }

        Stage addCastStage = new Stage();
        addCastStage.initModality(Modality.APPLICATION_MODAL);
        addCastStage.setTitle("Add Cast Member");

        addCastStage.getIcons().add(new Image("file:resources/icon.jpg"));

        VBox layout = new VBox(10);
        layout.setPadding(new Insets(10));
        layout.setSpacing(10);

        Label existingCastLabel = new Label("Select Existing Cast Member:");
        ComboBox<String> existingCastBox = new ComboBox<>();
        existingCastBox.getItems().addAll(getExistingCastMembers());
        TextField roleInput = new TextField();
        roleInput.setPromptText("Role");

        Button addExistingCastButton = new Button("Add Existing Cast Member");
        addExistingCastButton.setMaxWidth(575);
        addExistingCastButton.setOnAction(e -> {
            addExistingCastMemberToProduction(productionTitle, existingCastBox.getValue(), roleInput.getText(), castMembersList);
            addCastStage.close();
        });

        Label newCastLabel = new Label("Add New Cast Member:");
        TextField nameInput = new TextField();
        nameInput.setPromptText("Name");

        TextField emailInput = new TextField();
        emailInput.setPromptText("Email");

        TextField phoneInput = new TextField();
        phoneInput.setPromptText("Phone");

        TextField wageInput = new TextField();
        wageInput.setPromptText("Wage");

        wageInput.textProperty().addListener((observable, oldValue, newValue) -> {
            if (!newValue.matches("\\d*(\\.\\d*)?")) {
                wageInput.setText(oldValue);
            }
        });


        TextArea bioInput = new TextArea();
        bioInput.setPromptText("Bio");
        bioInput.setWrapText(true);

        TextField newRoleInput = new TextField();
        newRoleInput.setPromptText("Role");

        Button addNewCastButton = new Button("Add New Cast Member");
        addNewCastButton.setMaxWidth(575);
        addNewCastButton.setOnAction(e -> {
            addNewCastMemberToProduction(nameInput.getText(), emailInput.getText(), phoneInput.getText(), wageInput.getText(), bioInput.getText(), newRoleInput.getText(), castMembersList);
            addCastStage.close();
        });

        layout.getChildren().addAll(existingCastLabel, existingCastBox, roleInput, addExistingCastButton, newCastLabel, nameInput, emailInput, phoneInput, wageInput, bioInput, newRoleInput, addNewCastButton);

        Scene scene = new Scene(layout, 400, 600);
        scene.getStylesheets().add("file:resources/styles.css");
        addCastStage.setScene(scene);
        addCastStage.show();
    }




    private List<String> getExistingCastMembers() {
        List<String> castMembers = new ArrayList<>();
        try {
            PreparedStatement stmt = connection.prepareStatement("SELECT p.email FROM Person p JOIN CastMember cm ON p.person_id = cm.person_id");
            ResultSet rs = stmt.executeQuery();
            while (rs.next()) {
                castMembers.add(rs.getString("email"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return castMembers;
    }

    private void addExistingCastMemberToProduction(String productionTitle, String castEmail, String role, ObservableList<String> castMembersList) {
        if (castEmail == null || role.isEmpty()) {
            showErrorPopup("Please select a cast member and enter a role.");
            return;
        }

        castMembersList.add(castEmail + " as " + role);

        showSuccessPopup("Cast member added to list for production.");
    }


    private void addNewCastMemberToProduction(String name, String email, String phone, String wage, String bio, String role, ObservableList<String> castMembersList) {
        if (name.isEmpty() || email.isEmpty() || phone.isEmpty() || wage.isEmpty() || bio.isEmpty() || role.isEmpty()) {
            showErrorPopup("All fields must be filled out.");
            return;
        }

        try {
            connection.setAutoCommit(false);

            PreparedStatement personStmt = connection.prepareStatement("INSERT INTO Person (email, phone) VALUES (?, ?) RETURNING person_id");
            personStmt.setString(1, email);
            personStmt.setString(2, phone);
            ResultSet personRs = personStmt.executeQuery();
            int personId = 0;
            if (personRs.next()) {
                personId = personRs.getInt("person_id");
            }

            PreparedStatement detailsStmt = connection.prepareStatement("INSERT INTO PersonDetails (email, name) VALUES (?, ?)");
            detailsStmt.setString(1, email);
            detailsStmt.setString(2, name);
            detailsStmt.executeUpdate();

            PreparedStatement castStmt = connection.prepareStatement("INSERT INTO CastMember (person_id, wage, bio) VALUES (?, ?, ?)");
            castStmt.setInt(1, personId);
            castStmt.setBigDecimal(2, new BigDecimal(wage));
            castStmt.setString(3, bio);
            castStmt.executeUpdate();

            connection.commit();

            castMembersList.add(email + " as " + role);

            showSuccessPopup("New cast member added to list for production.");
        } catch (SQLException e) {
            e.printStackTrace();
            try {
                connection.rollback();
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }




    private void openAudiencePage(String email) {
        Stage audienceStage = new Stage();
        audienceStage.initModality(Modality.APPLICATION_MODAL);
        audienceStage.setTitle("Audience Dashboard");

        audienceStage.getIcons().add(new Image("file:resources/icon.jpg"));

        VBox layout = new VBox(10);
        layout.setPadding(new Insets(10));
        layout.setSpacing(10);

        Label performanceLabel = new Label("Select Performance:");
        performanceLabel.setMaxWidth(575);
        ComboBox<String> performanceBox = new ComboBox<>();

        Label productionLabel = new Label("Select Production:");
        productionLabel.setMaxWidth(575);
        ComboBox<String> productionBox = new ComboBox<>();
        List<String> productions = getProductions();
        productionBox.getItems().addAll(productions);
        productionBox.setOnAction(e -> updatePerformances(productionBox.getValue(), performanceBox));



        Button bookButton = new Button("Book Ticket");
        bookButton.setMaxWidth(575);
        bookButton.setOnAction(e -> bookTicketForAudience(email, performanceBox.getValue()));

        Button infoButton = new Button("Production Info");
        infoButton.setMaxWidth(575);
        infoButton.setOnAction(e -> showProductionInfo(productionBox.getValue()));

        Button myTicketsButton = new Button("My Tickets");
        myTicketsButton.setMaxWidth(575);
        myTicketsButton.setOnAction(e -> showMyTickets(email));

        Button commentsButton = new Button("Comments");
        commentsButton.setMaxWidth(575);
        commentsButton.setOnAction(e -> showProductionComments(productionBox.getValue()));

        Button membershipLevelButton = new Button("View Membership Level");
        membershipLevelButton.setMaxWidth(575);
        membershipLevelButton.setOnAction(e -> showMembershipLevel(email));

        Label commentLabel = new Label("Add a Comment:");
        TextArea commentArea = new TextArea();
        commentArea.setPromptText("Write your comment here...");
        commentArea.setWrapText(true);

        Label ratingLabel = new Label("Rating (1-5):");
        Slider ratingSlider = new Slider(1, 5, 3);
        ratingSlider.setMajorTickUnit(1);
        ratingSlider.setMinorTickCount(0);
        ratingSlider.setSnapToTicks(true);
        ratingSlider.setShowTickLabels(true);
        ratingSlider.setShowTickMarks(true);

        Button saveCommentButton = new Button("Save Comment");
        saveCommentButton.setMaxWidth(575);
        saveCommentButton.setOnAction(e -> saveComment(email, productionBox.getValue(), commentArea.getText(), (int) ratingSlider.getValue()));

        layout.getChildren().addAll(productionLabel, productionBox, performanceLabel, performanceBox, bookButton, infoButton, myTicketsButton, commentsButton, membershipLevelButton, commentLabel, commentArea, ratingLabel, ratingSlider, saveCommentButton);

        Scene scene = new Scene(layout, 400, 600);
        scene.getStylesheets().add("file:resources/styles.css");
        audienceStage.setScene(scene);

        audienceStage.setOnCloseRequest(event -> {
            resetDatabaseRole();
        });

        audienceStage.show();
    }

    private void showMembershipLevel(String email) {
        Stage popup = new Stage();
        popup.initModality(Modality.APPLICATION_MODAL);
        popup.setTitle("Membership Level");
        popup.getIcons().add(new Image("file:resources/icon.jpg"));

        TextArea membershipLevelArea = new TextArea();
        membershipLevelArea.setEditable(false);
        membershipLevelArea.setWrapText(true);

        try {
            PreparedStatement membershipStmt = connection.prepareStatement(
                    "SELECT a.membership_level " +
                            "FROM Audience a " +
                            "JOIN Person p ON a.person_id = p.person_id " +
                            "WHERE p.email = ?");
            membershipStmt.setString(1, email);
            ResultSet membershipRs = membershipStmt.executeQuery();

            if (membershipRs.next()) {
                membershipLevelArea.setText("Your membership level: " + membershipRs.getString("membership_level"));
            } else {
                membershipLevelArea.setText("Membership level not found.");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        VBox layout = new VBox(10);
        layout.setPadding(new Insets(10));
        layout.getChildren().add(membershipLevelArea);

        Scene scene = new Scene(layout, 300, 150);
        scene.getStylesheets().add("file:resources/styles.css");
        popup.setScene(scene);
        popup.showAndWait();
    }


    private void showProductionComments(String productionTitle) {
        if (productionTitle == null) {
            showErrorPopup("Please select a production.");
            return;
        }

        Stage popup = new Stage();
        popup.initModality(Modality.APPLICATION_MODAL);
        popup.setTitle("Production Comments");
        popup.getIcons().add(new Image("file:resources/icon.jpg"));

        TextArea commentsArea = new TextArea();
        commentsArea.setEditable(false);
        commentsArea.setWrapText(true);
        commentsArea.setPrefHeight(400);

        try {
            PreparedStatement fetchCommentaryDetailsStmt = connection.prepareStatement(
                    "SELECT date, rating, comment, commenter_name, membership_level " +
                            "FROM CommentaryDetails " +
                            "WHERE production_title = ?");
            fetchCommentaryDetailsStmt.setString(1, productionTitle);

            ResultSet commentsRs = fetchCommentaryDetailsStmt.executeQuery();

            StringBuilder commentsInfo = new StringBuilder("Comments for Production: " + productionTitle + "\n\n");
            while (commentsRs.next()) {
                commentsInfo.append("Date: ").append(commentsRs.getDate("date"))
                        .append("\nRating: ").append(commentsRs.getInt("rating"))
                        .append("\nComment: ").append(commentsRs.getString("comment"))
                        .append("\nCommenter: ").append(commentsRs.getString("commenter_name"))
                        .append("\nMembership Level: ").append(commentsRs.getString("membership_level"))
                        .append("\n\n");
            }

            commentsArea.setText(commentsInfo.toString());
        } catch (SQLException e) {
            e.printStackTrace();
        }

        VBox layout = new VBox(10);
        layout.setPadding(new Insets(10));
        layout.getChildren().add(commentsArea);

        Scene scene = new Scene(layout, 500, 400);
        scene.getStylesheets().add("file:resources/styles.css");
        popup.setScene(scene);
        popup.showAndWait();
    }


    private String hashPassword(String password) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hashedBytes = md.digest(password.getBytes());
            StringBuilder sb = new StringBuilder();
            for (byte b : hashedBytes) {
                sb.append(String.format("%02x", b));
            }
            return sb.toString();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return null;
        }
    }



    private void saveComment(String email, String productionTitle, String commentText, int rating) {
        if (productionTitle == null || commentText.isEmpty()) {
            showErrorPopup("Please select a production and enter a \ncomment.");
            return;
        }

        try {
            connection.setAutoCommit(false);

            PreparedStatement commentStmt = connection.prepareStatement(
                    "INSERT INTO Commentary (rating, comment, date) VALUES (?, ?, ?) RETURNING comment_id");
            commentStmt.setInt(1, rating);
            commentStmt.setString(2, commentText);
            commentStmt.setDate(3, new java.sql.Date(System.currentTimeMillis()));
            ResultSet commentRs = commentStmt.executeQuery();
            int commentId = 0;
            if (commentRs.next()) {
                commentId = commentRs.getInt("comment_id");
            }

            PreparedStatement audienceStmt = connection.prepareStatement(
                    "SELECT a.person_id FROM Audience a JOIN Person p ON a.person_id = p.person_id WHERE p.email = ?");
            audienceStmt.setString(1, email);
            ResultSet audienceRs = audienceStmt.executeQuery();
            int personId = 0;
            if (audienceRs.next()) {
                personId = audienceRs.getInt("person_id");
            }

            PreparedStatement productionStmt = connection.prepareStatement(
                    "SELECT production_id FROM production WHERE title = ?");
            productionStmt.setString(1, productionTitle);
            ResultSet productionRs = productionStmt.executeQuery();
            int productionId = 0;
            if (productionRs.next()) {
                productionId = productionRs.getInt("production_id");
            }

            PreparedStatement productionCommentStmt = connection.prepareStatement(
                    "INSERT INTO ProductionComment (production_id, comment_id) VALUES (?, ?)");
            productionCommentStmt.setInt(1, productionId);
            productionCommentStmt.setInt(2, commentId);
            productionCommentStmt.executeUpdate();

            PreparedStatement audienceCommentStmt = connection.prepareStatement(
                    "INSERT INTO AudienceComment (person_id, comment_id) VALUES (?, ?)");
            audienceCommentStmt.setInt(1, personId);
            audienceCommentStmt.setInt(2, commentId);
            audienceCommentStmt.executeUpdate();

            connection.commit();
            showSuccessPopup("Your comment has been saved successfully.");
        } catch (SQLException e) {
            e.printStackTrace();
            try {
                connection.rollback();
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }


    private void showMyTickets(String email) {
        Stage popup = new Stage();
        popup.initModality(Modality.APPLICATION_MODAL);
        popup.setTitle("My Tickets");

        popup.getIcons().add(new Image("file:resources/icon.jpg"));

        TextArea ticketsArea = new TextArea();
        ticketsArea.setEditable(false);
        ticketsArea.setWrapText(true);
        ticketsArea.setPrefHeight(400);

        try {
            PreparedStatement fetchTicketDetailsStmt = connection.prepareStatement(
                    "SELECT ticket_id, seat_number, price, purchase_date, date_and_time, venue_name, production_title " +
                            "FROM TicketDetails " +
                            "WHERE email = ?");
            fetchTicketDetailsStmt.setString(1, email);
            ResultSet ticketsRs = fetchTicketDetailsStmt.executeQuery();

            StringBuilder ticketsInfo = new StringBuilder("Your Tickets:\n");
            while (ticketsRs.next()) {
                ticketsInfo.append("Ticket ID: ").append(ticketsRs.getInt("ticket_id"))
                        .append("\nSeat Number: ").append(ticketsRs.getString("seat_number"))
                        .append("\nPrice: ").append(ticketsRs.getDouble("price"))
                        .append("\nPurchase Date: ").append(ticketsRs.getDate("purchase_date"))
                        .append("\nPerformance Date and Time: ").append(ticketsRs.getString("date_and_time"))
                        .append("\nVenue: ").append(ticketsRs.getString("venue_name"))
                        .append("\nProduction: ").append(ticketsRs.getString("production_title"))
                        .append("\n\n");
            }

            ticketsArea.setText(ticketsInfo.toString());
        } catch (SQLException e) {
            e.printStackTrace();
        }

        VBox layout = new VBox(10);
        layout.setPadding(new Insets(10));
        layout.getChildren().add(ticketsArea);

        Scene scene = new Scene(layout, 500, 400);
        scene.getStylesheets().add("file:resources/styles.css");
        popup.setScene(scene);
        popup.showAndWait();
    }


    private void showProductionInfo(String productionTitle) {
        Stage popup = new Stage();
        popup.initModality(Modality.APPLICATION_MODAL);
        popup.setTitle("Production Information");
        popup.getIcons().add(new Image("file:resources/icon.jpg"));

        TextArea infoArea = new TextArea();
        infoArea.setEditable(false);
        infoArea.setWrapText(true);
        infoArea.setPrefHeight(400);

        try {
            PreparedStatement productionStmt = connection.prepareStatement(
                    "SELECT pd.genre, pd.synopsis " +
                            "FROM ProductionDetails pd " +
                            "WHERE pd.title = ?");
            productionStmt.setString(1, productionTitle);
            ResultSet productionRs = productionStmt.executeQuery();
            StringBuilder productionInfo = new StringBuilder();
            if (productionRs.next()) {
                productionInfo.append("Genre: ").append(productionRs.getString("genre"))
                        .append("\nSynopsis: ").append(productionRs.getString("synopsis")).append("\n\n");
            }

            PreparedStatement venueStmt = connection.prepareStatement(
                    "SELECT v.name, v.address, v.facilities " +
                            "FROM ProductionVenue pv " +
                            "JOIN Production pr ON pv.production_id = pr.production_id " +
                            "JOIN Venue v ON pv.venue_id = v.venue_id " +
                            "WHERE pr.title = ?");
            venueStmt.setString(1, productionTitle);
            ResultSet venueRs = venueStmt.executeQuery();
            StringBuilder venueInfo = new StringBuilder("Available Venues:\n");
            while (venueRs.next()) {
                venueInfo.append("Name: ").append(venueRs.getString("name"))
                        .append("\nAddress: ").append(venueRs.getString("address"))
                        .append("\nFacilities: ").append(venueRs.getString("facilities")).append("\n\n");
            }

            PreparedStatement fetchCastDetailsStmt = connection.prepareStatement(
                    "SELECT cast_name, role " +
                            "FROM CastDetails " +
                            "WHERE production_title = ?");
            fetchCastDetailsStmt.setString(1, productionTitle);
            ResultSet castRs = fetchCastDetailsStmt.executeQuery();
            StringBuilder castInfo = new StringBuilder("Cast Members:\n");
            while (castRs.next()) {
                castInfo.append("Name: ").append(castRs.getString("cast_name"))
                        .append("\nRole: ").append(castRs.getString("role")).append("\n\n");
            }

            PreparedStatement fetchDirectorDetailsStmt = connection.prepareStatement(
                    "SELECT director_name, experience_years, awards, start_date, end_date " +
                            "FROM DirectorDetails " +
                            "WHERE production_title = ?");
            fetchDirectorDetailsStmt.setString(1, productionTitle);
            ResultSet directorRs = fetchDirectorDetailsStmt.executeQuery();

            StringBuilder directorInfo = new StringBuilder("Director:\n");
            if (directorRs.next()) {
                directorInfo.append("Name: ").append(directorRs.getString("director_name"))
                        .append("\nExperience Years: ").append(directorRs.getInt("experience_years"))
                        .append("\nAwards: ").append(directorRs.getString("awards")).append("\n\n")
                        .append("Start date: ").append(directorRs.getString("start_date"))
                        .append("\nEnd date: ").append(directorRs.getString("end_date")).append("\n\n");
            }

            infoArea.setText(productionInfo.toString() + venueInfo.toString() + castInfo.toString() + directorInfo.toString());
        } catch (SQLException e) {
            e.printStackTrace();
        }

        VBox layout = new VBox(10);
        layout.setPadding(new Insets(10));
        layout.getChildren().add(infoArea);

        Scene scene = new Scene(layout, 500, 400);
        scene.getStylesheets().add("file:resources/styles.css");
        popup.setScene(scene);
        popup.showAndWait();
    }




    private void bookTicketForAudience(String email, String selectedPerformance) {
        if (selectedPerformance == null) {
            showErrorPopup("Please select a performance.");
            return;
        }

        try {
            connection.setAutoCommit(false);

            String[] performanceDetails = selectedPerformance.split(" - ");
            int performanceId = Integer.parseInt(performanceDetails[0]);


            PreparedStatement ticketStmt = connection.prepareStatement("INSERT INTO Ticket (performance_id, price, purchase_date) VALUES (?, ?, ?) RETURNING ticket_id, seat_number");
            ticketStmt.setInt(1, performanceId);
            ticketStmt.setDouble(2, 50.0);
            ticketStmt.setDate(3, new java.sql.Date(System.currentTimeMillis()));
            ResultSet ticketRs = ticketStmt.executeQuery();
            int ticketId = 0;
            int seatNumber = 0;
            if (ticketRs.next()) {
                ticketId = ticketRs.getInt("ticket_id");
                seatNumber = ticketRs.getInt("seat_number");
            }

            PreparedStatement audienceStmt = connection.prepareStatement("SELECT a.person_id FROM Audience a JOIN Person p ON a.person_id = p.person_id WHERE p.email = ?");
            audienceStmt.setString(1, email);
            ResultSet audienceRs = audienceStmt.executeQuery();
            int personId = 0;
            if (audienceRs.next()) {
                personId = audienceRs.getInt("person_id");
            }

            PreparedStatement audienceTicketStmt = connection.prepareStatement("INSERT INTO AudienceTicket (person_id, ticket_id) VALUES (?, ?)");
            audienceTicketStmt.setInt(1, personId);
            audienceTicketStmt.setInt(2, ticketId);
            audienceTicketStmt.executeUpdate();

            connection.commit();
            showConfirmationPopup(seatNumber);


        } catch (SQLException e) {
            int iend = e.getMessage().indexOf(".");
            String subString = e.getMessage().substring(0 , iend);
            showErrorPopup(subString);
            try {
                connection.rollback();
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        } finally {
            try {
                connection.setAutoCommit(true);
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    private void showErrorPopup(String message) {
        Stage popup = new Stage();
        popup.initModality(Modality.APPLICATION_MODAL);
        popup.setTitle("Error");

        popup.getIcons().add(new Image("file:resources/icon.jpg"));

        Label label = new Label(message);
        VBox layout = new VBox(10);
        layout.setPadding(new Insets(10));
        layout.getChildren().add(label);

        Scene scene = new Scene(layout, 300, 100);
        scene.getStylesheets().add("file:resources/styles.css");
        popup.setScene(scene);
        popup.showAndWait();
    }

    private void showSuccessPopup(String message) {
        Stage popup = new Stage();
        popup.initModality(Modality.APPLICATION_MODAL);
        popup.setTitle("Success");

        popup.getIcons().add(new Image("file:resources/icon.jpg"));

        Label label = new Label(message);
        VBox layout = new VBox(10);
        layout.setPadding(new Insets(10));
        layout.getChildren().add(label);

        Scene scene = new Scene(layout, 300, 100);
        scene.getStylesheets().add("file:resources/styles.css");
        popup.setScene(scene);
        popup.showAndWait();
    }

    private void showConfirmationPopup(int seatNumber) {
        Stage popup = new Stage();
        popup.initModality(Modality.APPLICATION_MODAL);
        popup.setTitle("Ticket Booking Confirmation");

        popup.getIcons().add(new Image("file:resources/icon.jpg"));

        Label label = new Label("You have booked the ticket. You can get your ticket from \nthe counter. Please come as early as possible.\nYour seat number is: " + seatNumber);
        VBox layout = new VBox(10);
        layout.setPadding(new Insets(10));
        layout.getChildren().add(label);

        Scene scene = new Scene(layout, 400, 150);
        scene.getStylesheets().add("file:resources/styles.css");
        popup.setScene(scene);
        popup.showAndWait();
    }

    private void updatePerformances(String productionTitle, ComboBox<String> performanceBox) {
        performanceBox.getItems().clear();
        try {
            PreparedStatement stmt = connection.prepareStatement(
                    "SELECT performance_id, venue_name, date_and_time " +
                            "FROM PerformanceDetails " +
                            "WHERE title = ?");
            stmt.setString(1, productionTitle);
            ResultSet rs = stmt.executeQuery();
            while (rs.next()) {
                performanceBox.getItems().add(rs.getInt("performance_id") + " - " + rs.getString("venue_name") + " - " + rs.getString("date_and_time"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private List<String> getProductions() {
        List<String> productions = new ArrayList<>();
        try {
            Statement stmt = connection.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT title FROM production");
            while (rs.next()) {
                productions.add(rs.getString("title"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return productions;
    }

    public static void main(String[] args) {
        launch(args);
    }
}