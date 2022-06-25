public abstract class Building extends City{
	private int side;
	private int position;
	private int height;

	/**
	 * 	Constructor of Building superclass
	 * 	@param sideValue give side of the building
	 * 	@param lengthValue give length of the building
	 * 	@param positionValue give position of the building
	 * 	@param heightValue give height of the building
	 * 	@throws Exception throws if any unproper value is seen
	 */
	public Building(int sideValue, int lengthValue, int positionValue, int heightValue) throws Exception{
		super(lengthValue);
		setSide(sideValue);
		setPosition(positionValue);
		setHeight(heightValue);
	}

	/**
	 * 	Getter for the side.
	 * 	@return side of the building
	 */
	public int getSide(){
		return side;
	}

	/**
	 * 	Getter for the position.
	 * 	@return position of the building
	 */
	public int getPosition(){
		return position;
	}

	/**
	 * 	Getter for the height.
	 * 	@return height of the building
	 */
	public int getHeight(){
		return height;
	}

	/**
	 * 	Setter for the side.
	 * 	@param sideValue give side to the building
	 * 	@throws Exception thrown if any unproper side is seen
	 */
	public void setSide(int sideValue) throws Exception{
		if (sideValue != 0 && sideValue != 1) throw new Exception("Unproper side.");
		side = sideValue;
	}

	/**
	 * 	Setter for the position.
	 * 	@param positionValue give position to the building
	 * 	@throws Exception thrown if any unproper position is seen
	 */
	public void setPosition(int positionValue) throws Exception{
		if (positionValue < 0) throw new Exception("Unproper position.");
		position = positionValue;
	}

	/**
	 * 	Setter for the height.
	 * 	@param heightValue give height to the building
	 * 	@throws Exception thrown if any unproper height is seen
	 */
	public void setHeight(int heightValue) throws Exception{
		if (heightValue < 0) throw new Exception("Unproper height.");
		height = heightValue;
	}

	@Override
	/**
	 * 	Overridden string method.
	 * 	@return string to represent side, length, position, and height
	 */
	public String toString(){
		return String.format("%sSide: %d\nPosition: %d\nHeight: %d\n", super.toString(), getSide(), getPosition(), getHeight());
	}

	@Override
	/**
	 * 	Overridden equals method
	 * 	@param obj object to compare
	 * 	@return boolean that indicates if the objects are equal
	 */
	public boolean equals(Object obj){
		Building other = (Building) obj;
		if (!super.equals(obj)) return false;
		else if (getSide() != other.getSide() || getPosition()!=other.getPosition() || getHeight()!=other.getHeight()) return false;
		return true;
	}

	@Override
	/**
	 * 	Overridden clone method
	 * 	@return building that has been copied
	 */
	public Building clone(){
		try{
			Building copy = (Building) super.clone();
			return copy;
		}
		catch(Exception e){
			return null;
		}
	} 

	/**
	 * 	Abstract focus method, will be overridden in the subclasses
	 */
	public abstract String focus();
}