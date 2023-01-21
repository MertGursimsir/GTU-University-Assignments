public class House extends Building{
	private int roomNumber;
	private String color;
	private String owner;

	/**
	 * 	Constructor of subclass House
	 * 	@param sideValue give side to the house
	 * 	@param lengthValue give length to the house
	 * 	@param positionValue give position to the house
	 * 	@param heightValue give height to the house
	 * 	@param roomNumberValue give room number to the house
	 * 	@param colorValue give color to the house
	 * 	@param ownerValue give owner to the house
	 * 	@throws Exception thrown if any unproper value is seen
	 */
	public House(int sideValue, int lengthValue, int positionValue, int heightValue,
					int roomNumberValue, String colorValue, String ownerValue) throws Exception{
		super(sideValue, lengthValue, positionValue, heightValue);
		setRoomNumber(roomNumberValue);
		setColor(colorValue);
		setOwner(ownerValue);
	}

	@Override
	/**
	 * 	Overridden focus method
	 * 	@return gives owner information of the house as a string
	 */
	public String focus(){
		return "House's owner is -> " + getOwner();
	}

	/**
	 * 	Getter for the room number
	 * 	@return room number of the house
	 */
	public int getRoomNumber(){
		return roomNumber;
	}

	/**
	 *	Getter for the color
	 * 	@return color of the house
	 */
	public String getColor(){
		return color;
	}

	/**
	 * 	Getter for the owner
	 * 	@return owner of the house
	 */
	public String getOwner(){
		return owner;
	}

	/**
	 * 	Setter for the room number
	 * 	@param roomNumberValue give room number to the house
	 * 	@throws Exception thrown if unproper value is seen
	 */
	public void setRoomNumber(int roomNumberValue) throws Exception{
		if (roomNumberValue < 0) throw new Exception("Unproper room number.");
		roomNumber = roomNumberValue;
	}

	/**
	 * 	Setter for the color of the house
	 * 	@param colorValue give color to the house
	 */
	public void setColor(String colorValue){
		color = colorValue;
	}

	/**
	 * 	Setter for the owner of the house
	 * 	@param ownerValue give owner to the house
	 */
	public void setOwner(String ownerValue){
		owner = ownerValue;
	}

	@Override
	/**
	 * 	Overridden equals method
	 * 	@param obj object to compare
	 * 	@return boolean that indicates if the objects are equal
	 */
	public boolean equals(Object obj){
		House other = (House) obj;
		if (!super.equals(obj)) return false;
		else if (getRoomNumber() != other.getRoomNumber() || !getColor().equals(other.getColor()) || !getOwner().equals(other.getOwner())) return false;
		return true;
	}

	@Override
	/**
	 * 	Overridden clone method
	 * 	@return house that has been copied
	 */
	public House clone(){
		try{
			House copy = (House) super.clone();
			copy.color = new String(getColor());
			copy.owner = new String(getOwner());
			return copy;
		}
		catch(Exception e){
			return null;
		}
	} 

	@Override
	/**
	 * 	Overridden string method.
	 * 	@return string to represent properties of the house
	 */
	public String toString(){
		return String.format("\nHouse\n-----\n%sRoom Number: %d\nColor: %s\nOwner: %s\n", super.toString(), getRoomNumber(), getColor(), getOwner());
	}
}