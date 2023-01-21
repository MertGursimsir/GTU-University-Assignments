import java.util.*;
public interface Graph{
	/**
	 * Getter for the number of vertices.
	 * @return Returns number of vertices.
	 */
	int getNumV();

	/**
	 * Getter for the directed value.
	 * @return True if graph is directed, otherwise false.
	 */
	boolean isDirected();

	/**
	 * Method to insert given edge to the graph.
	 * @param edge Edge to be inserted
	 */
	void insert(MyGraph.Edge edge);

	/**
	 * Method to identify if there is an edge between given source and destionation values.
	 * @param source Source of the edge.
	 * @param dest Destination of the edge.
	 * @return True if edge exists, otherwise false.
	 */
	boolean isEdge(int source, int dest);

	/**
	 * Getter for the edge identified by source and destination.
	 * @param source Source of the edge.
	 * @param dest Destination of the edge.
	 * @return Edge that is identified by source and destination.
	 */
	MyGraph.Edge getEdge(int source, int dest);

	/**
	 * Method to return an iterator for the given vertex's edges.
	 * @param source ID of the vertex.
	 * @return Iterator for the given vertex's edges
	 */
	Iterator<MyGraph.Edge> edgeIterator(int source);
}