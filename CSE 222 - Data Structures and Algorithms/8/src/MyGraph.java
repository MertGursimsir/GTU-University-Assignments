import java.util.*;

/**
 * <h1>DYNAMIC MYGRAPH CLASS!</h1>
 * This class has methods for manipulating the graph
 * @author Mert Gürşimşir
 * @version 1.0 (June 2 2022)
 */

@SuppressWarnings("unchecked")
public class MyGraph implements DynamicGraph{
	/**
	 * Inner Edge class.
	 */
	public class Edge{
		private int dest;
		private int source;
		private double weight;

		/**
		 * Constructor to create edge from given source to dest with weight 1.0
		 * @param source Source of the edge.
		 * @param dest Destination of the edge.
		 */
		public Edge(int source, int dest){
			this.source = source;
			this.dest = dest;
			this.weight = 1.0;
		}

		/**
		 * Constructor to create edge from given source to dest with given weight
		 * @param source Source of the edge.
		 * @param dest Destination of the edge.
		 * @param weight Weight of the edge.
		 */
		public Edge(int source, int dest, double weight){
			this.source = source;
			this.dest = dest;
			this.weight = weight;
		}

		/**
		 * Equals method to identify if given edge and "this" edge are equal
		 * @param o Other Edge object
		 * @return True if two edges are equal, otherwise false
		 */
		public boolean equals(Object o){
			return (((Edge)o).source == source && ((Edge)o).dest == dest);
		}

		/**
		 * Getter for dest
		 * @return Destination of the edge.
		 */
		public int getDest(){
			return dest;
		}

		/**
		 * Getter for the source
		 * @return Source of the edge.
		 */
		public int getSource(){
			return source;
		}

		/**
		 * Getter for the weight
		 * @return Weight of the edge.
		 */
		public double getWeight(){
			return weight;
		}

		/**
		 * Overridden hashCode method to calculate hash code according to destination and source only
		 * @return Hash code of the Edge.
		 */
		public int hashCode(){
			return ((Integer)dest).hashCode() + ((Integer)source).hashCode();
		}

		/**
		 * Overridden toString method.
		 * @return String representation of the Edge.
		 */
		public String toString(){
			return "Source: " + source + ", Dest: " + dest + ", Weight: " + weight;
		}
	}

	/**
	 * Pair class for elements of the graph array.
	 * It has Vertex as a key, and LinkedList for according Edges.
	 */
	private class Pair{
		public Vertex key;
		public List<Edge> value;

		/**
		 * Constructor to start everything with null.
		 */
		public Pair(){
			key = null;
			value = null;
		}

		/**
		 * Constructor to create pair for given key and value.
		 * @param key Vertex of the pair.
		 * @param value Edge list for the pair.
		 */
		public Pair(Vertex key, List<Edge> value){
			this.key = key;
			this.value = value;
		}

		/**
		 * Getter for the Vertex
		 * @return Vertex of the pair
		 */
		public Vertex getKey(){
			return key;
		}

		/**
		 * Getter for the Edge LinkedList
		 * @return Edge LinkedList of the pair
		 */
		public List<Edge> getValue(){
			return value;
		}

		/**
		 * Overridden toString method
		 * @return String representation of the pair
		 */
		public String toString(){
			StringBuilder sb = new StringBuilder();
			sb.append(key.toString());
			if (value != null) for (Edge e : value) sb.append("     --> " + e + "\n");
			return sb.toString();
		}
	}

	private Pair[] edges;
	private int numV = 0;
	private int capacity;
	private int lastIndex = 0;
	private boolean directed;

	/**
	 * Constructor for the MyGraph
	 * @param capacity Start capacity of the graph.
	 * @param directed Boolean value to indicate if the graph is directed
	 * @throws Exception Throws exception if capacity is not proper (negative or zero)
	 */
	public MyGraph(int capacity, boolean directed) throws Exception{
		if (capacity <= 0) throw new Exception("Unproper capacity.");
		this.capacity = capacity;
		this.directed = directed;
		edges = new Pair[capacity];
	}

	/**
	 * Constructor for the MyGraph only with directed
	 * @param directed Boolean value to indicate if the graph is directed
	 */
	public MyGraph(boolean directed){
		this.capacity = 10;
		this.directed = directed;
		edges = new Pair[capacity];
	}

	/**
	 * No parameter constructor. Starts capacity with 10, and creates directed graph.
	 */
	public MyGraph(){
		this.capacity = 10;
		this.directed = true;
		edges = new Pair[capacity];
	}

	/**
	 * Generate a new vertex by given parameters.
	 * @param label Label of the vertex.
	 * @param weight Weight of the vertex.
	 * @return Returns generated vertex.
	 */
	public Vertex newVertex(String label, double weight){
		return new Vertex(label, weight);
	}

	/**
	 * Getter for the number of vertices.
	 * @return Returns number of vertices.
	 */
	public int getNumV(){
		return numV;
	}

	/**
	 * Getter for the last index of the graph array.
	 * @return Returns last index of the graph array.
	 */
	public int getLastIndex(){
		return lastIndex;
	}

	/**
	 * Add the given vertex to the graph.
	 * @param new_vertex Vertex to be added to the graph.
	 */
	public void addVertex(Vertex new_vertex){
		if (numV >= capacity) reallocate();
		for (int i = 0; i < lastIndex; ++i){
			if (edges[i] == null){
				new_vertex.setID(i);
				edges[i] = new Pair(new_vertex, new LinkedList<Edge>());
				numV++;
				return;
			}
		}
		new_vertex.setID(numV);
		edges[numV] = new Pair(new_vertex, new LinkedList<Edge>());
		numV++;
		lastIndex++;
	}

	/**
	 * Reallocation for the array
	 */
	private void reallocate(){
		capacity *= 2;
		edges = Arrays.copyOf(edges, capacity);
	}

	/**
	 * Print the graph in adjacency list format
	 */
	public void printGraph(){
		for (int i = 0; i < lastIndex; ++i) if (edges[i] != null) System.out.println(edges[i]);
	}

	/**
	 * Add an edge between the given two vertices in the graph.
	 * @param vertexID1 Source of the edge that will be added.
	 * @param vertexID2 Destination of the edge that will be added.
	 * @param weight Weight of the edge that will be added.
	 */
	public void addEdge(int vertexID1, int vertexID2, double weight){
		if (vertexID1 < 0 || vertexID1 >= lastIndex || vertexID2 < 0 || vertexID2 >= lastIndex) System.out.println("Unproper ID.");
		else if (weight < 0) System.out.println("Unproper weight.");
		else{
			Edge toAdd = new Edge(vertexID1, vertexID2, weight);
			for (Edge e:edges[vertexID1].getValue()){
				if (e.equals(toAdd)){ System.out.println("This edge already exists."); return;}
			}

			edges[vertexID1].value.add(toAdd);
			if (!directed) edges[vertexID2].value.add(new Edge(vertexID2, vertexID1, weight));
		}
	}

	/**
	 * Method to return an iterator for the given vertex's edges.
	 * @param source ID of the vertex.
	 * @return Iterator for the given vertex's edges
	 */
	public Iterator<Edge> edgeIterator(int source){
		if (source < 0 || source >= lastIndex) return null;
		if (edges[source] != null) return edges[source].value.iterator();
		else return null;
	}

	/**
	 * Remove the edge between the given two vertices.
	 * @param vertexID1 Source of the edge that will be deleted.
	 * @param vertexID2 Destination of the edge that will be deleted.
	 */
	public void removeEdge(int vertexID1, int vertexID2){
		if (vertexID1 < 0 || vertexID1 >= lastIndex || vertexID2 < 0 || vertexID2 >= lastIndex) System.out.println("Unproper ID.");
		else{
			boolean flag = true;
			Edge toDelete = new Edge(vertexID1, vertexID2, Double.POSITIVE_INFINITY);
			Iterator<Edge> iter = edgeIterator(vertexID1);
			if (iter == null){
				System.out.println("This edge does not exist.");
				return;
			}
			while (iter.hasNext()){
				if (iter.next().equals(toDelete)){
					iter.remove();
					flag = false;
					break;
				}
			}
			if (flag){
				System.out.println("This edge does not exist.");
				return;
			}
			if (!directed){
				Edge toDelete2 = new Edge(vertexID2, vertexID1, Double.POSITIVE_INFINITY);
				Iterator<Edge> iter2 = edgeIterator(vertexID2);
				while (iter2.hasNext()){
					if (iter2.next().equals(toDelete2)){
						iter2.remove();
						break;
					}
				}
			}
		}
	}

	/**
	 * Remove the vertex from the graph with respect to the given vertex id.
	 * @param vertexID ID of the vertex that will be removed.
	 */
	public void removeVertex(int vertexID){
		if (vertexID < 0 || vertexID >= lastIndex || edges[vertexID] == null) System.out.println("Unproper ID.");
		else{
			for (int i = 0; i < lastIndex; ++i){
				if (edges[i] != null && i != vertexID){
					Iterator<Edge> iter = edgeIterator(i);
					while (iter.hasNext()){
						if (iter.next().getDest() == vertexID){
							iter.remove();
							break;
						}
					}
				}
			}
			edges[vertexID] = null;
			numV--;
		}
	}

	/**
	 * Remove the vertices that have the given label from the graph.
	 * @param label Label of the vertex which will be removed.
	 */
	public void removeVertex(String label){
		for (int i = 0; i < lastIndex; ++i){
			if (edges[i] != null){
				if (edges[i].key.getLabel().equals(label)) removeVertex(i);
			}
		}
	}

	/**
	 * Filter the vertices by the given user-defined property and returns a subgraph of the graph.
	 * @param key Key of the property
	 * @param filter Value of the property
	 * @return New MyGraph object
	 */
	public MyGraph filterVertices(String key, String filter){
		try{
			MyGraph toReturn = new MyGraph(capacity, directed);
			for (int i = 0; i < lastIndex; ++i){
				if (edges[i] != null){
					Map<String, String> properties = edges[i].getKey().getProperties();
					for (Map.Entry<String, String> entry : properties.entrySet()){

						if (entry.getKey().equals(key) && entry.getValue().equals(filter)){
							toReturn.edges[i] = new Pair(null, new LinkedList<Edge>());
							toReturn.edges[i].key = new Vertex(i, edges[i].getKey().getLabel(), edges[i].getKey().getWeight(), (HashMap<String,String>)edges[i].getKey().getProperties().clone());
							
							Iterator<Edge> iter = edgeIterator(i);
							while (iter.hasNext()){
								Edge edge = iter.next();
								Map<String, String> properties2 = edges[edge.getDest()].getKey().getProperties();
								for (Map.Entry<String, String> entry2 : properties2.entrySet()){
									if (entry2.getKey().equals(key) && entry2.getValue().equals(filter)){
										toReturn.edges[i].value.add(new Edge(edge.getSource(), edge.getDest(), edge.getWeight()));
									}
								}
							}
							toReturn.numV++;
							toReturn.lastIndex = i+1;
							break;
						}
					}
				}
			}
			return toReturn;
		}
		/*Below part never happens*/
		catch(Exception e){e.printStackTrace();}
		return new MyGraph();
	}

	/**
	 * Generate the adjacency matrix representation of the graph and returns the matrix.
	 * @return AdjacencyMatrix representation of the graph.
	 */
	public Edge[][] exportMatrix(){
		Edge[][] toReturn = new Edge[lastIndex][lastIndex];

		for (int i = 0; i < lastIndex; ++i){
			if (edges[i] != null){
				Iterator<Edge> iter = edgeIterator(i);
				while(iter.hasNext()){
					Edge edge = iter.next();
					toReturn[edge.getSource()][edge.getDest()] = edge;
				}
			}
		}

		return toReturn;
	}

	/**
	 * Prints the given adjacency matrix.
	 * @param matrix Adjacency matrix.
	 */
	public void printMatrix(Edge[][] matrix){
		for (int i = 0; i < getLastIndex(); ++i){
			for (int j = 0; j < getLastIndex(); ++j){
				if (matrix[i][j] != null) System.out.printf("%3d ", 1);
				else if (!isThereVertex(i)) System.out.printf("%3d ", -1);
				else System.out.printf("%3d ", 0);
			}
			System.out.println();
		}
	}

	/**
	 * Checks if there is a vertex in given position.
	 * @param i ID of the vertex.
	 * @return True if vertex exists, otherwise false.
	 */
	public boolean isThereVertex(int i){
		if (i < 0 || i >= lastIndex) return false;
		return edges[i] != null;
	}

	/**
	 * Getter for the edge identified by source and destination.
	 * @param source Source of the edge.
	 * @param dest Destination of the edge.
	 * @return Edge that is identified by source and destination.
	 */
	public Edge getEdge(int source, int dest){
		Edge target = new Edge(source, dest, Double.POSITIVE_INFINITY);
		for (Edge edge : edges[source].value){
			if (edge.equals(target)) return edge;
		}
		return target;
	}

	/**
	 * Getter for the boost value for vertex at the given ID.
	 * @param source Source of the vertex.
	 * @return Boost value if "boosting" property exists, otherwise infinity
	 */
	public double getBoost(int source){
		if (edges[source].key.getProperties().containsKey("boosting"))
			return Double.parseDouble(edges[source].key.getProperties().get("boosting"));
		else return Double.POSITIVE_INFINITY;
	}

	/**
	 * Getter for the directed value.
	 * @return True if graph is directed, otherwise false.
	 */
	public boolean isDirected(){
		return directed;
	}

	/**
	 * Method to insert given edge to the graph.
	 * @param edge Edge to be inserted
	 */
	public void insert(Edge edge){
		addEdge(edge.getSource(), edge.getDest(), edge.getWeight());
	}

	/**
	 * Method to identify if there is an edge between given source and destionation values.
	 * @param source Source of the edge.
	 * @param dest Destination of the edge.
	 * @return True if edge exists, otherwise false.
	 */
	public boolean isEdge(int source, int dest){
		if (source < 0 || source >= lastIndex || dest < 0 || dest >= lastIndex || edges[source] == null) return false;

		return edges[source].value.contains(new Edge(source, dest));
	}
}