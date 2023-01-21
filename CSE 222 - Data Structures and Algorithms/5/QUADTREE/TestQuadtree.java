public class TestQuadtree{
	public static void main(String[] args){
		Quadtree test = new Quadtree();
		//System.out.printf("Nodes traversed during insertion of (30, 30):\n");
		test.add(30,30);
		System.out.printf("Resulting tree after insertion of (30, 30):\n");
		System.out.printf("%s", test);
		System.out.printf("\n*********************************\n");

		//System.out.printf("Nodes traversed during insertion of (20, 15):\n");
		test.add(20,15);
		System.out.printf("Resulting tree after insertion of (20, 15):\n");
		System.out.printf("%s", test);
		System.out.printf("\n*********************************\n");

		//System.out.printf("Nodes traversed during insertion of (50, 40):\n");
		test.add(50,40);
		System.out.printf("Resulting tree after insertion of (50, 40):\n");
		System.out.printf("%s", test);
		System.out.printf("\n*********************************\n");

		//System.out.printf("Nodes traversed during insertion of (10, 12):\n");
		test.add(10,12);
		System.out.printf("Resulting tree after insertion of (10, 12):\n");
		System.out.printf("%s", test);
		System.out.printf("\n*********************************\n");

		//System.out.printf("Nodes traversed during insertion of (40, 20):\n");
		test.add(40,20);
		System.out.printf("Resulting tree after insertion of (40, 20):\n");
		System.out.printf("%s", test);
		System.out.printf("\n*********************************\n");

		//System.out.printf("Nodes traversed during insertion of (25, 60):\n");
		test.add(25,60);
		System.out.printf("Resulting tree after insertion of (25, 60):\n");
		System.out.printf("%s", test);
		System.out.printf("\n*********************************\n");

		//System.out.printf("Nodes traversed during insertion of (15, 25):\n");
		test.add(15,25);
		System.out.printf("Resulting tree after insertion of (15, 25):\n");
		System.out.printf("%s", test);
	}
}