import java.util.Scanner;

public class DriverLinkedList{
	private static StreetLinkedList street;

	public static void main(String[] args){
		boolean continueLoop = true;
		Scanner scanner = new Scanner(System.in);
		
		//SELF-CHECK
		System.out.println("~~~QUICK CHECK ALL FUNCTIONALITIES~~~");
		System.out.println("-------------------------------------");
				 
		//long start = System.nanoTime();
		//Added to calculate time

		try{
			//ADDING BUILDINGS TO STREET
			street = new StreetLinkedList(60);
			street.add(new House(0, 10, 0, 10, 5, "Blue", "Erdogan Hoca"));
			street.add(new Office(0, 10, 10, 7, "Cyber Security", "Mert"));
			street.add(new Market(0, 5, 25, 5, "08:00", "21:00", "Burak Hoca"));
			street.add(new Playground(0, 10, 30));
			street.add(new Market(0, 5, 40, 4, "09:00", "22:00", "Zuckerberg"));
			street.add(new Office(0, 15, 45, 8, "Law Firm", "Mandela"));
			street.add(new Market(1, 10, 5, 12, "07:00", "23:00", "Murakami"));
			street.add(new Office(1, 15, 15, 14, "Quantum Computing", "Feynman"));

			//TRYING FUNCTIONALITIES		
			System.out.println("A street whose length is 60 is created and 8 new buildings have been added to it.");
			System.out.printf("List of the buildings: %s", street.buildingsList());
			System.out.printf("\nSilhouette of the street:\n");
			street.silhouette();
			System.out.printf("Total remaining length of lands on street: %s\n", street.remainingLands());
			System.out.printf("Number of playgrounds in the street: %d\n", street.numberOfPlaygrounds());
			System.out.printf("Ratio of playgrounds in the street: %f\n", street.ratioOfPlaygrounds());
			System.out.printf("Total length of the street occupied by markets: %d\n", street.marketLength());
			System.out.printf("Total length of the street occupied by houses: %d\n", street.houseLength());
			System.out.printf("Total length of the street occupied by offices: %d\n", street.officeLength());

			//DELETE SOME BUILDINGS AND RETRY FUNCTIONALITIES
			System.out.println("Now delete buildings that belong to Mert, Zuckerberg, Mandela, and Murakami.");
			street.delete(0, 10); street.delete(0, 40); street.delete(0, 45); street.delete(1, 5);
			
			System.out.println("\nNow try functionalities again.\n------------------------------");
			System.out.printf("List of the buildings: %s", street.buildingsList());
			System.out.printf("\nSilhouette of the street:\n");
			street.silhouette();
			System.out.printf("Total remaining length of lands on street: %s\n", street.remainingLands());
			System.out.printf("Number of playgrounds in the street: %d\n", street.numberOfPlaygrounds());
			System.out.printf("Ratio of playgrounds in the street: %f\n", street.ratioOfPlaygrounds());
			System.out.printf("Total length of the street occupied by markets: %d\n", street.marketLength());
			System.out.printf("Total length of the street occupied by houses: %d\n", street.houseLength());
			System.out.printf("Total length of the street occupied by offices: %d\n", street.officeLength());

			System.out.printf("\nNow focus on the buildings on the street.\n");
			System.out.printf("Erdogan Hoca's house's focus method:\n     %s\n", street.getBuilding(0,0).focus());
			System.out.printf("Burak Hoca's market's focus method:\n     %s\n", street.getBuilding(0,25).focus());
			System.out.printf("Playground's focus method:\n     %s\n", street.getBuilding(0,30).focus());
			System.out.printf("Feynman's office's focus method:\n     %s\n", street.getBuilding(1,15).focus());

			//SHOWING HANDLED ERRORS
			try{
				System.out.println("\nNow let's try to add a building to a position that is not empty.");
				System.out.println("We will add to the side 0, position 0, to the place of house that belongs to Erdogan Hoca.");
				street.add(new House(0, 10, 0, 10, 5, "Red", "No-one"));
			}
			catch(Exception e){
				System.err.printf("Exception: %s\n", e);
				System.out.println("This one gave an error as you see.\n");
			}
			try{
				System.out.println("\nNow let's try to add a building to a position that exceeds the boundaries of the street.");
				System.out.println("We will add to the side 0, position 100.");
				street.add(new House(0, 10, 100, 10, 5, "Red", "No-one"));
			}
			catch(Exception e){
				System.err.printf("Exception: %s\n", e);
				System.out.println("This one gave an error as you see.\n");
			}
			try{
				System.out.println("\nNow let's try to add a building to an unproper side, for example to side 4.");
				street.add(new House(4, 10, 1, 10, 5, "Red", "No-one"));
			}
			catch(Exception e){
				System.err.printf("Exception: %s\n", e);
				System.out.println("This one gave an error as you see.\n");
			}
			try{
				System.out.println("\nNow let's try to add a building that has unproper height like -5.");
				street.add(new House(1, 10, 40, -5, 5, "Red", "No-one"));
			}
			catch(Exception e){
				System.err.printf("Exception: %s\n", e);
				System.out.println("This one gave an error as you see.\n");
			}
			try{
				System.out.println("\nNow let's try to delete an empty space.");
				System.out.println("We will try to delete position at the end of the side 1 which is empty.");
				street.delete(1, 59);
			}
			catch(Exception e){
				System.err.printf("Exception: %s\n", e);
				System.out.println("This one gave an error as you see.\n");
			}
		}
		catch(Exception e){
			System.err.printf("Exception: %s\n", e);
			System.out.println("Please try again.\n");
		}
				
		//long end = System.nanoTime();
		//long total = end - start;
		//System.out.println(total);
		//Added to calculate time

		/**************************************************************************************************************/
		//USER-CHECK
		System.out.println("~~~NOW STREET OF BEAUTIFUL THINGS WELCOMES YOU~~~");
		System.out.println("-------------------------------------------------");
		
		//Getting length of the street from user
		do{
			try{
				System.out.printf("\nPlease enter length of the street: ");
				int streetLength = scanner.nextInt();
				street = new StreetLinkedList(streetLength);
				continueLoop = false;
			}
			catch (Exception e){
				scanner.nextLine();
				System.err.printf("Exception: %s\n", e);
				System.out.println("Please try again.\n");
			}
		}while (continueLoop);

		//Choosing the mode
		continueLoop = true;
		do{
			try{
				System.out.println("\nPlease choose from the menu: ");
				System.out.println("1 -> Editing Mode");
				System.out.println("2 -> Viewing Mode");
				System.out.println("3 -> Exit");
				System.out.printf("Choice: ");
				int menuChoice = scanner.nextInt();
				switch(menuChoice){
					case 1: editModeMenu();
							break;
					case 2: viewingModeMenu();
							break;
					case 3: continueLoop = false;
							break;
					default: System.out.println("Please choose between 1-3.");
				}
			}
			catch (Exception e){
				scanner.nextLine();
				System.err.printf("Exception: %s\n", e);
				System.out.println("Please try again.\n");
			}
		}while(continueLoop);

		System.out.println("~~~So long! See you next time.~~~");
	}

	public static void editModeMenu(){
		//Edit mode to add or delete buildings
		Scanner scanner = new Scanner(System.in);
		boolean continueLoop = true;
		System.out.println("\nWelcome to editing mode!");
		do{
			try{
				System.out.println("Please choose from the menu:");
				System.out.println("1 -> Add to street");
				System.out.println("2 -> Delete from street");
				System.out.printf("Choice: ");
				int editChoice = scanner.nextInt();
				switch(editChoice){
					case 1: addMenu();
							break;
					case 2: deleteMenu();
							break;
					default: System.out.println("Please choose 1 or 2.");
				}
				continueLoop = false;
			}
			catch (Exception e){
				scanner.nextLine();
				System.err.printf("Exception: %s\n", e);
				System.out.println("Please try again.\n");
			}
		}while(continueLoop);
	}

	public static void addMenu(){
		Scanner scanner = new Scanner(System.in);
		boolean continueLoop = true;

		//Getting input and adding buildings
		do{
			try{
				System.out.printf("\nWhich side of the street do you want to add (0 or 1): ");
				int sideChoice = scanner.nextInt();
				if (sideChoice != 0 && sideChoice != 1) { System.out.println("Try again."); continue;}

				System.out.println("\nWhich of the followings do you want to add to street: ");
				System.out.println("1 -> House");
				System.out.println("2 -> Office");
				System.out.println("3 -> Market");
				System.out.println("4 -> Playground");
				System.out.printf("Choice: ");
				int buildingChoice = scanner.nextInt();
				
				if (buildingChoice == 1){
					System.out.printf("\nPlease enter length of the house: ");
					int houseLength = scanner.nextInt();
					System.out.printf("Please enter position of the house: ");
					int housePosition = scanner.nextInt();
					System.out.printf("Please enter height of the house: ");
					int houseHeight = scanner.nextInt();
					System.out.printf("Please enter number of rooms of the house: ");
					int houseRooms = scanner.nextInt();
					System.out.printf("Please enter color of the house: ");
					scanner.nextLine();
					String houseColor = scanner.nextLine();
					System.out.printf("Please enter owner of the house: ");
					String houseOwner = scanner.nextLine();
					try{
						street.add(new House(sideChoice, houseLength, housePosition, houseHeight, houseRooms, houseColor, houseOwner));
					}
					catch (Exception e){
						System.err.printf("Exception: %s\n", e);
						System.out.println("Please try again.\n");
					}
				}
				else if (buildingChoice == 2){
					System.out.printf("\nPlease enter length of the office: ");
					int officeLength = scanner.nextInt();
					System.out.printf("Please enter position of the office: ");
					int officePosition = scanner.nextInt();
					System.out.printf("Please enter height of the office: ");
					int officeHeight = scanner.nextInt();
					System.out.printf("Please enter job type: ");
					scanner.nextLine();
					String officeJobType = scanner.nextLine();
					System.out.printf("Please enter owner of the office: ");
					String officeOwner = scanner.nextLine();
					try{
						street.add(new Office(sideChoice, officeLength, officePosition, officeHeight, officeJobType, officeOwner));
					}
					catch (Exception e){
						System.err.printf("Exception: %s\n", e);
						System.out.println("Please try again.\n");
					}
				}
				else if (buildingChoice == 3){
					System.out.printf("\nPlease enter length of the market: ");
					int marketLength = scanner.nextInt();
					System.out.printf("Please enter position of the market: ");
					int marketPosition = scanner.nextInt();
					System.out.printf("Please enter height of the market: ");
					int marketHeight = scanner.nextInt();
					System.out.printf("Please enter owner of the market: ");
					scanner.nextLine();
					String marketOwner = scanner.nextLine();
					System.out.printf("Please enter opening time of the market (HH:MM): ");
					String marketOpeningTime = scanner.nextLine();
					System.out.printf("Please enter closing time of the market (HH:MM): ");
					String marketClosingTime = scanner.nextLine();
					try{
						street.add(new Market(sideChoice, marketLength, marketPosition, marketHeight, marketOpeningTime, marketClosingTime, marketOwner));
					}
					catch (Exception e){
						System.err.printf("Exception: %s\n", e);
						System.out.println("Please try again.\n");
					}
				}
				else if (buildingChoice == 4){
					System.out.printf("\nPlease enter length of the playground: ");
					int playgroundLength = scanner.nextInt();
					System.out.printf("Please enter position of the playground: ");
					int playgroundPosition = scanner.nextInt();
					try{
						street.add(new Playground(sideChoice, playgroundLength, playgroundPosition));
					}
					catch (Exception e){
						System.err.printf("Exception: %s\n", e);
						System.out.println("Please try again.\n");
					}	
				}
				else { System.out.println("Try again."); continue;}
				continueLoop = false;
			}
			catch (Exception e){
				scanner.nextLine();
				System.err.printf("Exception: %s\n", e);
				System.out.println("Please try again.\n");
			}
		}while(continueLoop);

	}

	public static void deleteMenu(){
		Scanner scanner = new Scanner(System.in);
		boolean continueLoop = true;

		//Delete the building in the specified side and position
		do{
			try{
				System.out.printf("Please enter the side you want to delete from (-1 to exit): ");
				int sideChoice = scanner.nextInt();
				if (sideChoice == -1) return;
				System.out.printf("Please enter the position you want to delete from: ");
				int positionChoice = scanner.nextInt();
				street.delete(sideChoice, positionChoice);
				continueLoop = false;
			}
			catch (Exception e){
				scanner.nextLine();
				System.err.printf("Exception: %s\n", e);
				System.out.println("Please try again.\n");
			}
		}while(continueLoop);
	}

	public static void viewingModeMenu(){
		Scanner scanner = new Scanner(System.in);
		boolean continueLoop = true;
		System.out.println("\nWelcome to viewing mode!");

		//Viewing mode to display some properties
		do{
			try{
				System.out.println("Please choose from the menu: ");
				System.out.println("1 -> Display the total remaining length of lands on the street");
				System.out.println("2 -> Display the list of buildings on the street");
				System.out.println("3 -> Display the number and ratio of length of playgrounds in the street");
				System.out.println("4 -> Calculate the total length of street occupied by the markets, houses or offices");
				System.out.println("5 -> Display the skyline silhouette of the street");
				System.out.println("6 -> Focus on a building");
				System.out.printf("Choice: ");
				int viewChoice = scanner.nextInt();

				if (viewChoice == 1) System.out.printf("\nTotal remaining length of lands on the street ----> %d\n", street.remainingLands());
				else if (viewChoice == 2) System.out.println(street.buildingsList());
				else if (viewChoice == 3){
					System.out.printf("\nNumber of playgrounds ----> %d\n", street.numberOfPlaygrounds());
					System.out.printf("\nRatio of playgrounds  ----> %f\n", street.ratioOfPlaygrounds());
				}
				else if (viewChoice == 4){
					System.out.println("Please choose which of the building's total length you want to see: ");
					System.out.println("1 -> House");
					System.out.println("2 -> Office");
					System.out.println("3 -> Market");
					System.out.printf("Choice: ");
					int buildingChoice = scanner.nextInt();
					if (buildingChoice == 1) System.out.printf("\nTotal length of street occupied by houses: %d\n", street.houseLength());
					else if (buildingChoice == 2) System.out.printf("\nTotal length of street occupied by offices: %d\n", street.officeLength());
					else if (buildingChoice == 3) System.out.printf("\nTotal length of street occupied by markets: %d\n", street.marketLength());
					else { System.out.println("Try again."); continue;}
				}
				else if (viewChoice == 5) street.silhouette();
				else if (viewChoice == 6){
					System.out.printf("Please enter the side your building exists: ");
					int sideChoice = scanner.nextInt();
					System.out.printf("Please enter the position of your building: ");
					int positionChoice = scanner.nextInt();
					System.out.println(street.getBuilding(sideChoice, positionChoice).focus());
				}
				else { System.out.println("Try again."); continue;}
				continueLoop = false;
			}
			catch (Exception e){
				scanner.nextLine();
				System.err.printf("Exception: %s\n", e);
				System.out.println("Please try again.\n");
			}
		}while(continueLoop);
	}
}