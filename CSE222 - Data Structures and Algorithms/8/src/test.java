public class test{
	public static void main(String[] args){
		try{
			System.out.println("WELCOME TO TEST OF THE DYNAMIC GRAPH AND ITS APPLICATIONS");
			System.out.println("---------------------------------------------------------\n");

			System.out.println("Creating new undirected graph and adding 11 new vertex to it:");
			MyGraph tester = new MyGraph(1, false);
			Vertex v1 = new Vertex("Mert", 42, "length", "7");
			Vertex v2 = new Vertex("Ahsen", 30, "length", "7");
			Vertex v3 = new Vertex("Sevilgen", 100, "boosting", "3");
			Vertex v4 = new Vertex("Burak", 100, "color", "red");
			Vertex v5 = new Vertex("Ferda", 100, "boosting", "15");
			Vertex v6 = new Vertex("Murakami", 33, "boosting", "3");
			Vertex v7 = new Vertex("Feynman", 62, "size", "57");
			Vertex v8 = new Vertex("Stephen", 99, "boosting", "15");
			Vertex v9 = new Vertex("Michio", 71, "color", "blue");
			Vertex v10 = new Vertex("Hugo", 6, "boosting", "8");
			Vertex v11 = tester.newVertex("Turing", 17.);
			v1.addProperty("color", "red");
			v2.addProperty("color", "red");
			v11.addProperty("color", "red");
			tester.addVertex(v1); tester.addVertex(v2); tester.addVertex(v3);
			tester.addVertex(v4); tester.addVertex(v5); tester.addVertex(v6);
			tester.addVertex(v7); tester.addVertex(v8); tester.addVertex(v9);
			tester.addVertex(v10);tester.addVertex(v11);
			tester.printGraph();

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Adding edges to graph:\n");
			tester.addEdge(0, 1, 11); tester.addEdge(0, 3, 13); tester.addEdge(1, 2, 14);
			tester.addEdge(1, 4, 15); tester.addEdge(1, 6, 16); tester.addEdge(1, 7, 17);
			tester.addEdge(2, 3, 3);  tester.addEdge(2, 8, 8);  tester.addEdge(2, 9, 9);
			tester.addEdge(4, 5, 25); tester.addEdge(4, 6, 26); tester.addEdge(4, 7, 16);
			tester.addEdge(6, 7, 6);  tester.addEdge(2, 10, 8);
			tester.printGraph();

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Now filtering the vertices with key \"color\" and with filter \"red\":\n");
			tester.filterVertices("color", "red").printGraph();

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Now removing the vertices with label \"Michio\" and with index 0:\n");
			tester.removeVertex("Michio");
			tester.removeVertex(0);
			tester.printGraph();

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Now removing the edges from 1 to 6 and 6 to 7:\n");
			tester.removeEdge(1, 6); tester.removeEdge(6, 7);
			tester.printGraph();

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Now try to remove edge from non-existing index 0 to 4:\n");
			tester.removeEdge(0, 4);

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Also, if we try to delete a non-existing edge, it will indicate the error (try to delete edge from 1 to 10):\n");
			tester.removeEdge(1, 10);
			
			System.out.println("-----------------------------------------------------------------------");

			System.out.println("If we try to give negative weight, it will indicate the error (add edge between 1 and 10 with weight -1):\n");
			tester.addEdge(1,10,-1);

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Now exporting the matrix representation (-1 represents vertex doesn't exist):\n");
			MyGraph.Edge[][] matrix = tester.exportMatrix();
			tester.printMatrix(matrix);

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Now test the traversals (-2 represents vertex with that index doesn't exist, -1 represents there is no predecessor):\n");
			int difference = GraphApplications.differenceOfTraversals(tester);
			System.out.printf("Difference of traversals: %d\n\n", difference);

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Now test the dijkstras algorithm with boosting values (-2 represents vertex with that index doesn't exist, -1 represents there is no predecessor):\n");
			GraphApplications.dijkstrasAlgorithm(tester);

			System.out.println("\n\n=======================================================================\n");

			System.out.println("Creating new graph and adding 9 new vertex to it:");
			MyGraph tester2 = new MyGraph(false);
			v3.addProperty("boosting", "2");
			v5.addProperty("boosting", "4");
			v6.addProperty("boosting", "0");
			tester2.addVertex(v1); tester2.addVertex(v2); tester2.addVertex(v3);
			tester2.addVertex(v4); tester2.addVertex(v5); tester2.addVertex(v6);
			tester2.addVertex(v7);
 			tester2.printGraph();

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Adding edges to graph:\n");
			tester2.addEdge(0,1,13); tester2.addEdge(0,2,9); tester2.addEdge(0,3,10); 
			tester2.addEdge(0,4,9);  tester2.addEdge(1,4,6); tester2.addEdge(1,3,7);
			tester2.addEdge(3,4,4);  tester2.addEdge(2,5,3); tester2.addEdge(2,6,2); tester2.addEdge(5,6,1);
			tester2.printGraph();

			System.out.println("-----------------------------------------------------------------------");
			
			System.out.println("Now test the traversals:\n");
			difference = GraphApplications.differenceOfTraversals(tester2);
			System.out.printf("Difference of traversals: %d\n\n", difference);

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Now test the dijkstras algorithm with boosting values:\n");
			GraphApplications.dijkstrasAlgorithm(tester2);

			System.out.println("\n\n=======================================================================\n");
			
			System.out.println("Creating new directed graph and adding 4 new vertex to it:");
			Vertex v111 = new Vertex("Mert", 42, "boosting", "2");
			Vertex v222 = new Vertex("Ahsen", 30, "boosting", "3");
			Vertex v333 = new Vertex("Sevilgen", 100, "boosting", "4");
			Vertex v444 = new Vertex("Burak", 100, "boosting", "4");
			MyGraph tester3 = new MyGraph();
			tester3.addVertex(v111); tester3.addVertex(v222); tester3.addVertex(v333); tester3.addVertex(v444);
			tester3.printGraph();

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Adding edges to graph:\n");
			tester3.addEdge(0,1,4);   tester3.addEdge(0,2,4); tester3.addEdge(1,2,5);
			tester3.addEdge(0,3,10); tester3.addEdge(2,3,5); tester3.addEdge(1,3,5);
			tester3.printGraph();

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Now removing the edges connected to 0:\n");
			tester3.removeEdge(0, 1); tester3.removeEdge(0, 2); tester3.removeEdge(0, 3);
			tester3.printGraph();

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Now test the dijkstras algorithm with boosting values:\n");
			GraphApplications.dijkstrasAlgorithm(tester3);

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Now adding the edges again:\n");
			tester3.insert(tester3.new Edge(0,1,4)); tester3.insert(tester3.new Edge(0,2,4)); tester3.insert(tester3.new Edge(0,3,10));
			tester3.printGraph();

			System.out.println("-----------------------------------------------------------------------");
			
			System.out.println("Now test the traversals:\n");
			difference = GraphApplications.differenceOfTraversals(tester3);
			System.out.printf("Difference of traversals: %d\n\n", difference);

			System.out.println("-----------------------------------------------------------------------");

			System.out.println("Now test the dijkstras algorithm with boosting values:\n");
			GraphApplications.dijkstrasAlgorithm(tester3);

			System.out.println("\n\n=======================================================================\n");
		}
		catch(Exception e){
			e.printStackTrace();
			System.out.println(e);
		}
	}
}