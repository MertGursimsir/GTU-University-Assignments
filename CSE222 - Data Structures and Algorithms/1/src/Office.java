public class Office extends Building{
	private String jobType;
	private String owner;

	/**
	 * 	Constructor of subclass Office
	 * 	@param sideValue give side to the office
	 * 	@param lengthValue give length to the office
	 * 	@param positionValue give position to the office
	 * 	@param heightValue give height to the office
	 * 	@param jobTypeValue give job type to the office
	 * 	@param ownerValue give owner to the office
	 * 	@throws Exception thrown if any unproper value is seen
	 */
	public Office(int sideValue, int lengthValue, int positionValue, int heightValue,
					String jobTypeValue, String ownerValue) throws Exception{
		super(sideValue, lengthValue, positionValue, heightValue);
		setJobType(jobTypeValue);
		setOwner(ownerValue);
	}

	@Override
	/**
	 * 	Overridden focus method
	 * 	@return gives job type information of the office as a string
	 */
	public String focus(){
		return "Office's job type is -> " + getJobType();
	}

	/**
	 * 	Getter for the job type
	 * 	@return job type of the office
	 */
	public String getJobType(){
		return jobType;
	}

	/**
	 * 	Getter for the owner
	 * 	@return owner of the office
	 */
	public String getOwner(){
		return owner;
	}

	/**
	 * 	Setter for the job type
	 * 	@param jobTypeValue give job type to office
	 */
	public void setJobType(String jobTypeValue){
		jobType = jobTypeValue;
	}

	/**
	 * 	Setter for the owner
	 * 	@param ownerValue give owner to office
	 */
	public void setOwner(String ownerValue){
		owner = ownerValue;
	}

	@Override
	/**
	 * 	Overridden string method.
	 * 	@return string to represent properties of the office
	 */
	public String toString(){
		return String.format("\nOffice\n------\n%sJob Type: %s\nOwner: %s\n", super.toString(), getJobType(), getOwner());
	}

	@Override
	/**
	 * 	Overridden equals method
	 * 	@param obj object to compare
	 * 	@return boolean that indicates if the objects are equal
	 */
	public boolean equals(Object obj){
		Office other = (Office) obj;
		if (!super.equals(obj)) return false;
		else if (!getJobType().equals(other.getJobType()) || !getOwner().equals(other.getOwner())) return false;
		return true;
	}

	@Override
	/**
	 * 	Overridden clone method
	 * 	@return office that has been copied
	 */
	public Office clone(){
		try{
			Office copy = (Office) super.clone();
			copy.jobType = new String(getJobType());
			copy.owner = new String(getOwner());
			return copy;
		}
		catch(Exception e){
			return null;
		}
	} 
}