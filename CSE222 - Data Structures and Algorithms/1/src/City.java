public class City{
	private int length;

	/**
	 * 	Constructor for the City class
	 * 	@param lengthValue give length
	 */
	public City(int lengthValue) throws Exception{
		setLength(lengthValue);
	}

	/**
	 * 	Getter for the length
	 * 	@return length
	 */
	public int getLength(){
		return length;
	}

	/**
	 * 	Setter for the length
	 * 	@param lengthValue for length
	 * 	@throws Exception thrown if length is unproper
	 */
	public void setLength(int lengthValue) throws Exception{
		if (lengthValue <= 0) throw new Exception("Unproper length.");
		length = lengthValue;
	}

	@Override
	/**
	 * 	Overridden string method.
	 * 	@return string to represent length
	 */
	public String toString(){
		return String.format("Length: %d\n", getLength());
	}

	@Override
	/**
	 * 	Overridden equals method
	 * 	@param obj object to compare
	 * 	@return boolean that indicates if the objects are equal
	 */
	public boolean equals(Object obj){
		City other = (City) obj;
		if (other.getLength() != getLength()) return false;
		return true;
	}

	@Override
	/**
	 * 	Overridden clone method
	 * 	@return city that has been copied
	 */
	public City clone(){
		try{
			City copy = (City) super.clone();
			return copy;
		}
		catch(Exception e){
			return null;
		}
	} 
}