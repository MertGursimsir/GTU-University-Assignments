public interface DynamicGraph extends Graph{
	/**
	 * Generate a new vertex by given parameters.
	 * @param label Label of the vertex.
	 * @param weight Weight of the vertex.
	 * @return Returns generated vertex.
	 */
	Vertex newVertex(String label, double weight);

	/**
	 * Add the given vertex to the graph.
	 * @param new_vertex Vertex to be added to the graph.
	 */
	void addVertex(Vertex new_vertex);

	/**
	 * Add an edge between the given two vertices in the graph.
	 * @param vertexID1 Source of the edge that will be added.
	 * @param vertexID2 Destination of the edge that will be added.
	 * @param weight Weight of the edge that will be added.
	 */
	void addEdge(int vertexID1, int vertexID2, double weight);

	/**
	 * Remove the edge between the given two vertices.
	 * @param vertexID1 Source of the edge that will be deleted.
	 * @param vertexID2 Destination of the edge that will be deleted.
	 */
	void removeEdge(int vertexID1, int vertexID2);

	/**
	 * Remove the vertex from the graph with respect to the given vertex id.
	 * @param vertexID ID of the vertex that will be removed.
	 */
	void removeVertex(int vertexID);

	/**
	 * Remove the vertices that have the given label from the graph.
	 * @param label Label of the vertex which will be removed.
	 */
	void removeVertex(String label);

	/**
	 * Filter the vertices by the given user-defined property and returns a subgraph of the graph.
	 * @param key Key of the property
	 * @param filter Value of the property
	 * @return New MyGraph object
	 */
	MyGraph filterVertices(String key, String filter);
	//returns new subgraph (dont alter main graph, create new and return)

	/**
	 * Generate the adjacency matrix representation of the graph and returns the matrix.
	 * @return AdjacencyMatrix representation of the graph.
	 */
	MyGraph.Edge[][] exportMatrix();

	/**
	 * Print the graph in adjacency list format
	 */
	void printGraph();
}