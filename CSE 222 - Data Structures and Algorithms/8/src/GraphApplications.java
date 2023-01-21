import java.util.*;

/**
 * <h1>GRAPH APPLICATIONS CLASS!</h1>
 * This class has breadth-first search, depth-first search, and dijkstras algorithm.
 * @author Mert Gürşimşir
 * @version 1.0 (June 2 2022)
 */

public class GraphApplications{
	/**
	 * Method to perform BFS and DFS traversals.
	 * @param graph Dynamic MyGraph object.
	 * @return The difference between the total distances of two traversal methods
	 */
	public static int differenceOfTraversals(MyGraph graph){
		int start = 0, distanceBFS = 0, distanceDFS = 0;
		while (!graph.isThereVertex(start)) start++;

		//Implementing traversals
		int[] parent = BFS(graph, start);
		DepthFirstSearch dfs = new DepthFirstSearch(graph);

		//Printing out the results
		System.out.printf("Parent array of the BFS: ");
		for (int i = 0; i < parent.length; ++i) System.out.printf("%2d ", parent[i]);

		System.out.printf("\n\nParent array of the DFS: ");
		for (int i = 0; i < dfs.getParent().length; ++i) System.out.printf("%2d ", dfs.getParent()[i]);

		System.out.printf("\nDiscovery order of the DFS: ");
		for (int i = 0; i < dfs.getDiscoveryOrder().length; ++i) System.out.printf("%2d ", dfs.getDiscoveryOrder()[i]);

		System.out.printf("\nFinish order of the DFS: ");
		for (int i = 0; i < dfs.getFinishOrder().length; ++i) System.out.printf("%2d ", dfs.getFinishOrder()[i]);

		//Calculating the distances
		for (int i = 0; i < graph.getLastIndex(); ++i){
			if (parent[i] >= 0){
				int temp = parent[i];
				while (temp != -1){
					temp = parent[temp];
					distanceBFS++;
				}
			}
			if (dfs.getParent()[i] >= 0){
				int temp = dfs.getParent()[i];
				while (temp != -1){
					temp = dfs.getParent()[temp];
					distanceDFS++;
				}
			}
		}

		System.out.printf("\n\nTotal distance of the BFS path: %d\n", distanceBFS);
		System.out.printf("Total distance of the DFS: %d\n", distanceDFS);

		return Math.abs(distanceBFS - distanceDFS);
	}

	/**
	 * Method to perform BFS.
	 * @param graph Dynamic MyGraph object.
	 * @param start Start index of the graph.
	 * @return Parent array of the traversal.
	 */
	public static int[] BFS(MyGraph graph, int start){
		Queue<Integer> queue = new LinkedList<Integer>();

		//Starting parent array
		int[] parent = new int[graph.getLastIndex()];
		for (int i = 0; i < graph.getLastIndex(); ++i){
			if (graph.isThereVertex(i)) parent[i] = -1; 
			else parent[i] = -2;
		}

		//Creating array for identified vertices
		boolean[] identified = new boolean[graph.getLastIndex()];
		identified[start] = true;
		queue.offer(start);

		while (!queue.isEmpty()){
			int curr = queue.remove();
			Iterator<MyGraph.Edge> iter = graph.edgeIterator(curr);
			while(iter.hasNext()){
				MyGraph.Edge edge = iter.next();
				int neighbor = edge.getDest();
				if (!identified[neighbor]){
					identified[neighbor] = true;
					queue.offer(neighbor);
					parent[neighbor] = curr;
				}
			}
		}

		return parent;
	}

	/**
	 * Inner class for DFS.
	 */
	public static class DepthFirstSearch{
		private int discoverIndex = 0;
		private int[] discoveryOrder;
		private int finishIndex = 0;
		private int[] finishOrder;
		private MyGraph graph;
		private int[] parent;
		private boolean[] visited;

		/**
		 * Constructor to perform depth first search
		 * @param graph Dynamic MyGraph object.
		 */
		public DepthFirstSearch(MyGraph graph){
			this.graph = graph;
			int n = graph.getLastIndex();
			parent = new int[n];
			visited = new boolean[n];
			discoveryOrder = new int[n];
			finishOrder = new int[n];

			for (int i = 0; i < n; ++i) parent[i] = -2;

			int current = 0;
			while (!graph.isThereVertex(current)) current++;
			depthFirstSearch(current);
			
			discoveryOrder = Arrays.copyOf(discoveryOrder, graph.getNumV());
			finishOrder = Arrays.copyOf(finishOrder, graph.getNumV());
		}

		/**
		 * Recursive method that actually performs DFS
		 * @param current Index to identify current vertex. 
		 */
		public void depthFirstSearch(int current){
			double min = Integer.MAX_VALUE;
			int nextID = 0;
			boolean flag = false;
			if (!visited[current]){
				parent[current] = -1;
				discoveryOrder[discoverIndex++] = current;
				visited[current] = true;
			}

			//Traverse through edges
			Iterator<MyGraph.Edge> iter = graph.edgeIterator(current);
			while (iter.hasNext()){
				MyGraph.Edge e = iter.next();
				if (e.getWeight() < min && !visited[e.getDest()]){
					min = e.getWeight();
					nextID = e.getDest();
					flag = true;
				}
			}

			//After traversing, apply same method recursively
			if (flag && !visited[nextID]){
				discoveryOrder[discoverIndex++] = nextID;
				visited[nextID] = true;
				parent[nextID] = current;
				depthFirstSearch(nextID);
			}

			Iterator<MyGraph.Edge> itr = graph.edgeIterator(current);
			while (itr.hasNext()){
				if (!visited[itr.next().getDest()]){
					flag = true;
					break;
				}
			}
			if (flag) depthFirstSearch(current);
			else finishOrder[finishIndex++] = current;
		}

		/**
		 * Getter for the discovery order
		 * @return discovery order
		 */
		public int[] getDiscoveryOrder(){
			return discoveryOrder;
		}

		/**
		 * Getter for the finish order
		 * @return finish order
		 */
		public int[] getFinishOrder(){
			return finishOrder;
		}

		/**
		 * Getter for the parent
		 * @return parent
		 */
		public int[] getParent(){
			return parent;
		}
	}


	/************************************************************************************************************************************/


	/**
	 * Starter method to perform dijkstras algorithm
	 * @param graph Dynamic MyGraph object.
	 */
	public static void dijkstrasAlgorithm(MyGraph graph){
		int start = 0;
		while (!graph.isThereVertex(start)) start++;

		int[] pred = new int[graph.getLastIndex()];
		double[] dist = new double[graph.getLastIndex()];
		dijkstrasAlgorithm(graph, start, pred, dist);

		System.out.printf("Predecessor array --> ");
		for (int i = 0; i < pred.length; ++i) System.out.printf("%d ", pred[i]);
		
		System.out.printf("\nDistance array --> ");
		for (int i = 0; i < dist.length; ++i) System.out.printf("%.2f ", dist[i]);
		System.out.println();
	}

	/**
	 * Method to perform dijkstras algorithm.
	 * @param graph Dynamic MyGraph object.
	 * @param start Start index of the graph.
	 * @param pred int array for predecessors.
	 * @param dist double array for distances.
	 */
	private static void dijkstrasAlgorithm(MyGraph graph, int start, int[] pred, double[] dist){
		HashSet<Integer> vMinusS = new HashSet<Integer>(graph.getNumV());

		for(int i = 0; i < graph.getLastIndex(); i++){
			if(i != start && graph.isThereVertex(i)) vMinusS.add(i);
		}
		for (int i = 0; i < pred.length; ++i){
			pred[i] = -2; dist[i] = -2.;
			if (i == start){
				pred[i] = -1;
				dist[i] = 0;
			}
		}
		for(int v : vMinusS){
			pred[v] = start;
			dist[v] = graph.getEdge(start, v).getWeight();
		}

		//Removing unreachable vertices
		DepthFirstSearch dfs = new DepthFirstSearch(graph); //DFS is for identify unvisited vertices
		for (int i = 0; i < dfs.visited.length; ++i){
			if (!dfs.visited[i] && graph.isThereVertex(i)){
				pred[i] = -1;
				vMinusS.remove(i);
			}
		}

		//Perform until there is no vertex left
		while(vMinusS.size() != 0){
			double minDist = Double.POSITIVE_INFINITY;
			int u = -1;
			for(int v : vMinusS){				
				if(dist[v] < minDist){
					minDist = dist[v];
					u = v;
				}
			}

			vMinusS.remove(u);

			Iterator<MyGraph.Edge> edgeIter = graph.edgeIterator(u);

			while(edgeIter != null && edgeIter.hasNext()){
				MyGraph.Edge edge = edgeIter.next();
				int v = edge.getDest();
				if(vMinusS.contains((Integer)v)){
					double distance = edge.getWeight() + dist[u];
					if (graph.getBoost(u) != Double.POSITIVE_INFINITY) distance -= graph.getBoost(u);
					
					if(distance < dist[v]){
						dist[v] = distance;
						pred[v] = u;
					}
				}
			}
		}
	}
}