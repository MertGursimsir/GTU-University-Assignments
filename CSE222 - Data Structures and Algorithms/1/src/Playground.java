public class Playground extends Building{
	/**
	 * 	Constructor of subclass playground
	 * 	@param sideValue give side to the playground
	 * 	@param lengthValue give length to the playground
	 * 	@param positionValue give position to the playground
	 * 	@throws Exception thrown if any unproper value is seen
	 */
	public Playground(int sideValue, int lengthValue, int positionValue) throws Exception{
		super(sideValue, lengthValue, positionValue, 2);
	}

	@Override
	/**
	 * 	Overridden focus method
	 * 	@return gives length information of the playground as a string
	 */
	public String focus(){
		return "Playground's length is -> " + Integer.toString(getLength());
	}

	@Override
	/**
	 * 	Overridden string method.
	 * 	@return string to represent properties of the playground
	 */
	public String toString(){
		return String.format("\nPlayground\n----------\n%s", super.toString());
	}

	@Override
	/**
	 * 	Overridden equals method
	 * 	@param obj object to compare
	 * 	@return boolean that indicates if the objects are equal
	 */
	public boolean equals(Object obj){
		Playground other = (Playground) obj;
		if (!super.equals(obj)) return false;
		return true;
	}

	@Override
	/**
	 * 	Overridden clone method
	 * 	@return playground that has been copied
	 */
	public Playground clone(){
		try{
			Playground copy = (Playground) super.clone();
			return copy;
		}
		catch(Exception e){
			return null;
		}
	} 
}