public class Quadtree{
	/**
	 * Inner class for point data
	 */
	private class TwoDPoint{
		private int x;
		private int y;
		/**
		 * Constructor.
		 * @param xTemp x value of the point
		 * @param yTemp y value of the point
		 */
		private TwoDPoint(int xTemp, int yTemp){
			x = xTemp;
			y = yTemp;
		}
	}

	private class Area{
		private double xCenter;
		private double yCenter;
		private double height;
		private double width;
		/**
		 * Constructor
		 * @param xCenterTemp x value of the center of the area
		 * @param yCenterTemp y value of the center of the area
		 * @param widthTemp width of the area
		 * @param heightTemp height of the area
		 */
		private Area(double xCenterTemp, double yCenterTemp, double widthTemp, double heightTemp){
			xCenter = xCenterTemp;
			yCenter = yCenterTemp;
			height = heightTemp;
			width = widthTemp;
		}
	}
	
	private TwoDPoint point = null;
	private Area rectangle;
	private boolean isDivided = false;
	private boolean full = false;
	private Quadtree NW;
	private Quadtree NE;
	private Quadtree SW;
	private Quadtree SE;

	/**
	 * No-parameter constructor
	 * Creates the Quadtree with 100x100 area
	 */
	public Quadtree(){
		rectangle = new Area(50, 50, 50, 50);
	}

	/**
	 * Constructor
	 * Creates the Quadtree with given area
	 */
	private Quadtree(Area rect){
		rectangle = rect;
	}

	/**
	 * 	Check if point belongs to the area
	 * 	@param x x value of the point
	 * 	@param y y value of the point
	 * 	@return boolean value to indicate if point belongs to the area
	 */
	private boolean contains(int x, int y){
		return (x <= (rectangle.xCenter + rectangle.width)) && (x >= (rectangle.xCenter - rectangle.width)) &&
               (y <= (rectangle.yCenter + rectangle.height))&& (y >= (rectangle.yCenter - rectangle.height));
	}

	/**
	 * Divides the area into 4 quadrants
	 */
	private void divide(){
	    NW = new Quadtree(new Area(rectangle.xCenter-rectangle.width/2, rectangle.yCenter-rectangle.height/2, rectangle.width/2, rectangle.height/2));
	    NE = new Quadtree(new Area(rectangle.xCenter+rectangle.width/2, rectangle.yCenter-rectangle.height/2, rectangle.width/2, rectangle.height/2));
	    SW = new Quadtree(new Area(rectangle.xCenter-rectangle.width/2, rectangle.yCenter+rectangle.height/2, rectangle.width/2, rectangle.height/2));
	    SE = new Quadtree(new Area(rectangle.xCenter+rectangle.width/2, rectangle.yCenter+rectangle.height/2, rectangle.width/2, rectangle.height/2));
	    isDivided = true;
	}

	/**
	 * Adds given point to the Quadtree
	 * @param x x value of the point
	 * @param y y value of the point
	 * @return boolean value to indicate if insertion is successful
	 */
	public boolean add(int x, int y){
		if (!contains(x, y)) return false;
		if (!full){
			point = new TwoDPoint(x, y);
			full = true;
			return true;
		}
		else{
			//System.out.printf("(%d, %d)\n", point.x, point.y);
			if (!isDivided) divide();

			/*if (point != null){
				if (!NW.add(point.x, point.y)){
					if (!NE.add(point.x, point.y)){
						if (!SW.add(point.x, point.y)){
							SE.add(point.x, point.y);
						}
					}
				}
				traversed.add(point);
				point = null;
			}*/

			if (NW.add(x, y)) return true;
	        else if (NE.add(x, y)) return true;
	        else if (SW.add(x, y)) return true;
	        else if (SE.add(x, y)) return true;
	        else return false;
		}
	}

	/**
	 * Overridden string method
	 * @return String representation of the tree
	 */
	public String toString(){
		StringBuilder sb = new StringBuilder();
		Traverse(this, 1, sb);
		return sb.toString();
	}

	/**
	 * Traverse through the tree and add datas to the stringbuilder
	 * @param root Root of the current tree
	 * @param depth Depth of the current tree
	 * @param sb StringBuilder to add datas
	 */
	private void Traverse(Quadtree root, int depth, StringBuilder sb){
		for (int i = 1; i < depth; ++i) sb.append("-");
		if (root.point == null) sb.append("null\n");
		else{
			sb.append("(");
			sb.append(root.point.x);
			sb.append(", ");
			sb.append(root.point.y);
			sb.append(")\n");
		}
		if (root.isDivided){
			Traverse(root.NW, depth+1, sb);
			Traverse(root.NE, depth+1, sb);
			Traverse(root.SW, depth+1, sb);
			Traverse(root.SE, depth+1, sb);
		}
	}
}