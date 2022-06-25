public class Market extends Building{
	private String openingTime;
	private String closingTime;
	private String owner;

	/**
	 * 	Constructor of subclass Market
	 * 	@param sideValue give side to the market
	 * 	@param lengthValue give length to the market
	 * 	@param positionValue give position to the market
	 * 	@param heightValue give height to the market
	 * 	@param openingTimeValue give opening time to the market
	 * 	@param closingTimeValue give closing time to the market
	 * 	@param ownerValue give owner to the market
	 * 	@throws Exception thrown if any unproper value is seen
	 */
	public Market(int sideValue, int lengthValue, int positionValue, int heightValue,
					String openingTimeValue, String closingTimeValue, String ownerValue) throws Exception{
		super(sideValue, lengthValue, positionValue, heightValue);
		setOpeningTime(openingTimeValue);
		setClosingTime(closingTimeValue);
		setOwner(ownerValue);
	}

	@Override
	/**
	 * 	Overridden focus method
	 * 	@return gives closing time information of the market as a string
	 */
	public String focus(){
		return "Market's closing time is -> " + getClosingTime();
	}

	/**
	 * 	Getter for the opening time
	 * 	@return opening time of the market
	 */
	public String getOpeningTime(){
		return openingTime;
	}

	/**
	 * 	Getter for the closing time
	 * 	@return closing time of the market
	 */
	public String getClosingTime(){
		return closingTime;
	}

	/**
	 * 	Getter for the owner
	 * 	@return owner of the market
	 */
	public String getOwner(){
		return owner;
	}

	/**
	 * 	Setter for the opening time of the market
	 * 	@param openingTimeValue give opening time to the market
	 * 	@throws Exception thrown if unproper time format is seen
	 */
	public void setOpeningTime(String openingTimeValue) throws Exception{
		if (openingTimeValue.charAt(2) != ':' || openingTimeValue.length() != 5) throw new Exception("Unproper time."); 
		else{
			for (int i = 0; i < 4; ++i){
				if (i!=2 && !Character.isDigit(openingTimeValue.charAt(i))) throw new Exception("Unproper time.");
			}
		}

		int hour = (openingTimeValue.charAt(0)-'0')*10 + (openingTimeValue.charAt(1)-'0');
		int minute = (openingTimeValue.charAt(3)-'0')*10 + (openingTimeValue.charAt(4)-'0');
		if (hour < 0 || hour > 23 || minute < 0 || minute > 59) throw new Exception("Unproper time."); 

		openingTime = openingTimeValue;
	}

	/**
	 * 	Setter for the closing time of the market
	 * 	@param closingTimeValue give closing time to the market
	 * 	@throws Exception thrown if unproper time format is seen
	 */
	public void setClosingTime(String closingTimeValue) throws Exception{
		if (closingTimeValue.charAt(2) != ':' || closingTimeValue.length() != 5) throw new Exception("Unproper time."); 
		else{
			for (int i = 0; i < 4; ++i){
				if (i!=2 && !Character.isDigit(closingTimeValue.charAt(i))) throw new Exception("Unproper time.");
			}
		}

		int hour = (closingTimeValue.charAt(0)-'0')*10 + (closingTimeValue.charAt(1)-'0');
		int minute = (closingTimeValue.charAt(3)-'0')*10 + (closingTimeValue.charAt(4)-'0');
		if (hour < 0 || hour > 23 || minute < 0 || minute > 59) throw new Exception("Unproper time."); 

		closingTime = closingTimeValue;
	}

	/**
	 * 	Setter for the owner of the market
	 * 	@param ownerValue give owner to the market 
	 */
	public void setOwner(String ownerValue){
		owner = ownerValue;
	}

	@Override
	/**
	 * 	Overridden string method.
	 * 	@return string to represent properties of the market
	 */
	public String toString(){
		return String.format("\nMarket\n------\n%sOpening Time: %s\nClosing Time: %s\nOwner: %s\n", super.toString(), getOpeningTime(), getClosingTime(), getOwner());
	}

	@Override
	/**
	 * 	Overridden equals method
	 * 	@param obj object to compare
	 * 	@return boolean that indicates if the objects are equal
	 */
	public boolean equals(Object obj){
		Market other = (Market) obj;
		if (!super.equals(obj)) return false;
		else if (!getOpeningTime().equals(other.getOpeningTime()) || !getClosingTime().equals(other.getClosingTime()) || !getOwner().equals(other.getOwner())) return false;
		return true;
	}

	@Override
	/**
	 * 	Overridden clone method
	 * 	@return market that has been copied
	 */
	public Market clone(){
		try{
			Market copy = (Market) super.clone();
			copy.openingTime = new String(getOpeningTime());
			copy.closingTime = new String(getClosingTime());
			copy.owner = new String(getOwner());
			return copy;
		}
		catch(Exception e){
			return null;
		}
	} 
}