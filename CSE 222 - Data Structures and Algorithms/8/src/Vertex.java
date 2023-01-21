import java.util.*;

/**
 * <h1>GENERAL VERTEX CLASS!</h1>
 * This class has properties for the vertices of the graph.
 * @author Mert Gürşimşir
 * @version 1.0 (June 2 2022)
 */

public class Vertex{
	private int ID = -1;
	private String label; //not unique
	private double weight; //not used in any calculation
	private Map<String, String> properties;
	
	/**
	 * Constructor with label and weight
	 * @param label Label value of the vertex
	 * @param weight Weight value of the vertex
	 */
	public Vertex(String label, double weight){
		properties = null;
		this.label = label;
		this.weight = weight;
	}

	/**
	 * Constructor with label, weight, key-value pair for one property
	 * @param label Label value of the vertex
	 * @param weight Weight value of the vertex
	 * @param key Key of the property
	 * @param value Value of the property
	 */
	public Vertex(String label, double weight, String key, String value){
		properties = new HashMap<>();
		properties.put(key, value);
		this.label = label;
		this.weight = weight;
	}

	/**
	 * Constructor with ID, label, weight, properties
	 * @param ID ID of the vertex, if it is determined by the user, it could be changed afterwards according to situation of the graph array
	 * @param label Label value of the vertex
	 * @param weight Weight value of the vertex
	 * @param properties Properties map of the vertex
	 */
	public Vertex(int ID, String label, double weight, Map<String, String> properties){
		this.ID = ID;
		this.label = label;
		this.weight = weight;
		this.properties = properties;
	}

	/**
	 * Method to add property to the vertex
	 * @param key Key of the property
	 * @param value Value of the property
	 */
	public void addProperty(String key, String value){
		if (properties == null) properties = new HashMap<>();
		properties.put(key, value);
	}

	/**
	 * Overridden toString method
	 * @return String representation of the Vertex
	 */
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append("ID: " + ID + ", Label: " + label + ", Weight: " + weight);
		if (properties != null){
			for (Map.Entry<String, String> entry : properties.entrySet()){
				sb.append(", Key: " + entry.getKey() + " <=> Value: " + entry.getValue());
			}
		}
		sb.append("\n");
		return sb.toString();
	}

	/**
	 * Setter for the ID, if you are user, no need to use this.
	 * @param id ID value of the vertex.
	 */
	public void setID(int id){
		ID = id;
	}

	/**
	 * Getter for the ID
	 * @return Returns ID of the vertex
	 */
	public int getID(){
		return ID;
	}

	/**
	 * Getter for the label
	 * @return Returns label of the vertex
	 */
	public String getLabel(){
		return label;
	}

	/**
	 * Getter for the weight
	 * @return Returns weight of the vertex
	 */
	public double getWeight(){
		return weight;
	}

	/**
	 * Getter for the properties
	 * @return Returns properties of the vertex
	 */
	public HashMap<String, String> getProperties(){
		return (HashMap<String, String>)properties;
	}

	/**
	 * Overridden equals method
	 * @param o Other vertex
	 * @return Returns true if two vertices are equal, otherwise
	 */
	public boolean equals(Object o){
		return 	((Vertex)o).getLabel().equals(getLabel())
				&& ((Vertex)o).getWeight() == getWeight()
				&& ((Vertex)o).getProperties().equals(getProperties());
	}

	
}