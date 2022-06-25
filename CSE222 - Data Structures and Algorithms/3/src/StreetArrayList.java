import java.util.ArrayList;

/**
 * <h1>STREET CONTAINER CLASS!</h1>
 * This class has ArrayList to keep buildings for 2 sides of the street.
 * @author Mert Gürşimşir
 * @version 1.0 (March 19 2022)
 */
@SuppressWarnings("unchecked") // for unchecked type warning.
public class StreetArrayList extends City{
	private ArrayList<Building> street0;
	private ArrayList<Building> street1;

	/**
	 *	Constructor of StreetArray with lengthValue.
	 * 	Assign ArrayList's length to parameter.
	 *  @param lengthValue give length to street 
	 */
	public StreetArrayList(int lengthValue) throws Exception{
		super(lengthValue);
		street0 = new ArrayList<Building>(getLength());
		street1 = new ArrayList<Building>(getLength());
		for (int i = 0; i < getLength(); ++i){
			street0.add(null);
			street1.add(null);
		}
	}

	/**
	 *	Adding method that adds given building to street.
	 * 	@param building building to be added to street 
	 * 	@throws Exception thrown if any out of bounds, or unproper values errors seen
	 */
	public void add(Building building) throws Exception{
		//Checking possible errors
        if (building.getLength() > getLength()) throw new Exception("Out of bounds.");
        if (building.getPosition() + building.getLength() > getLength()) throw new Exception("Building exceeds the limit of the street.");
        if (!isEmpty(building)) throw new Exception("That place is not empty.");

        //Adding building
        for(int i = building.getPosition(), j = 0; j < building.getLength(); ++i, ++j){
        	if (building instanceof House){
        		House temp = (House) building;
        		if (temp.getSide() == 0) street0.add(i, new House(temp.getSide(), temp.getLength(), temp.getPosition(), temp.getHeight(),
															temp.getRoomNumber(), temp.getColor(), temp.getOwner()) );
        		else street1.add(i, new House(temp.getSide(), temp.getLength(), temp.getPosition(), temp.getHeight(),
															temp.getRoomNumber(), temp.getColor(), temp.getOwner()) );
        	}
        	else if (building instanceof Office){
        		Office temp = (Office) building;
        		if (temp.getSide() == 0) street0.add(i, new Office(temp.getSide(), temp.getLength(), temp.getPosition(), temp.getHeight(),
															temp.getJobType(), temp.getOwner()));
        		else street1.add(i, new Office(temp.getSide(), temp.getLength(), temp.getPosition(), temp.getHeight(),
															temp.getJobType(), temp.getOwner()));
        	}
        	else if (building instanceof Market){
        		Market temp = (Market) building;
        		if (temp.getSide() == 0) street0.add(i, new Market(temp.getSide(), temp.getLength(), temp.getPosition(), temp.getHeight(),
															temp.getOpeningTime(), temp.getClosingTime(), temp.getOwner()));
        		else street1.add(i, new Market(temp.getSide(), temp.getLength(), temp.getPosition(), temp.getHeight(),
															temp.getOpeningTime(), temp.getClosingTime(), temp.getOwner()));
        	}
        	else if (building instanceof Playground){
        		Playground temp = (Playground) building;
        		if (temp.getSide() == 0) street0.add(i, new Playground(temp.getSide(), temp.getLength(), temp.getPosition()));
        		else street1.add(i, new Playground(temp.getSide(), temp.getLength(), temp.getPosition()));
        	}
        }
	}

	/**
	 *	Delete method that deletes building in specified side and position
	 * 	@param side side of the building
	 * 	@param position position of the building
	 * 	@throws Exception thrown if any out of bounds, attempting to delete empty space, or unproper values errors seen
	 */
	public void delete(int side, int position) throws Exception{
		//Checking possible errors
		if (position >= getLength() || position < 0) throw new Exception("Out of bounds.");
		if (side != 0 && side != 1) throw new Exception("Unproper side.");
		if (side == 0){ if (street0.get(position) == null) throw new Exception("Attempting to delete empty space.");}
		else if (street1.get(position) == null) throw new Exception("Attempting to delete empty space.");
	
		int tempPosition, tempLength;
		if (side == 0) tempPosition = street0.get(position).getPosition();
		else tempPosition = street1.get(position).getPosition();
		if (side == 0) tempLength = street0.get(position).getLength();
		else tempLength = street1.get(position).getLength();

		for (int i = tempPosition, j = 0; j < tempLength; ++i, ++j){
			if (side == 0) street0.set(i, null);
			else street1.set(i, null);
		}
	}

	/**
	 * 	To check if there is enough space for the building that will be added.
	 * 	@param building building to be added to street
	 * 	@return true if there is enough space, otherwise false
	 */
    public boolean isEmpty(Building building){
    	int place = 0;
    	for(int i = building.getPosition(), j = 0; j < building.getLength(); ++i, ++j){
    		if (building.getSide() == 0){
    			if (street0.get(i) != null) return false;
    		}
    		else{
    			if (street1.get(i) != null) return false;
    		}
    	}
    	return true;
	}

	/**
	 * 	Returns the remaining empty lands.
	 * 	@return remaining lands in the street
	 */
	public int remainingLands(){
		int remainingLands = 0;
		for (int i = 0; i < getLength(); ++i){
			if (street0.get(i) == null) remainingLands++;
			if (street1.get(i) == null) remainingLands++;
		}
		return remainingLands;
	}

	/**
	 * 	Shows list of the buildings on the street.
	 * 	@return string of the buildings.
	 */
	public String buildingsList(){
		//Listing side 0
		String list = "\nSIDE 0\n======\n";
		boolean flag = true;
		for (int i = 0; i < getLength(); ++i){
			if (street0.get(i) != null){
				list = list + street0.get(i);
				i += street0.get(i).getLength()-1;
				flag = false;
			}
		}
		if (flag) list = list + "\nThere is nothing on this side of the street\n";
		else flag = true;

		//Listing side 1
		list = list + "\nSIDE 1\n======\n";
		for (int i = 0; i < getLength(); ++i){
			if (street1.get(i) != null){
				list = list + street1.get(i);
				i += street1.get(i).getLength()-1;
				flag = false;
			}
		}
		if (flag) list = list + "\nThere is nothing on this side of the street\n";
		return list;
	}

	/**
	 * 	Returns number of playgrounds on the street.
	 * 	@return number of playgrounds
	 */
	public int numberOfPlaygrounds(){
		int numOfPg = 0;
		//Looking side 0
		for (int i = 0; i < getLength(); ++i){
			if (street0.get(i) instanceof Playground){
				if (street0.get(i) != null){
					numOfPg++;
					i += street0.get(i).getLength()-1;
				}
			}
		}
		//Looking side 1
		for (int i = 0; i < getLength(); ++i){
			if (street1.get(i) instanceof Playground){
				if(street1.get(i) != null){
					numOfPg++;
					i += street1.get(i).getLength()-1;
				}
			}
		}
		return numOfPg;
	}

	/**
	 * 	Returns ratio of length of playgrounds in the street.
	 * 	@return double value for the ratio of length of playgrounds in the street
	 */
	public double ratioOfPlaygrounds(){
		double playgroundLength = 0.0;
		//Looking side 0 and adding playground lengths
		for (int i = 0; i < getLength(); ++i){
			if (street0.get(i) instanceof Playground){
				if (street0.get(i) != null){
					playgroundLength += street0.get(i).getLength();
					i += street0.get(i).getLength()-1;
				}
			}
		}
		//Looking side 1 and adding playground lengths
		for (int i = 0; i < getLength(); ++i){
			if (street1.get(i) instanceof Playground){
				if (street1.get(i) != null){
					playgroundLength += street1.get(i).getLength();
					i += street1.get(i).getLength()-1;
				}
			}
		}
		return playgroundLength / (getLength()*2);
	}

	/**
	 * 	Returns total length of markets in the street.
	 * 	@return total length of markets in the street
	 */
	public int marketLength(){
		int lengthOfMarkets = 0;
		//Looking side 0 and adding market lengths
		for (int i = 0; i < getLength(); ++i){
			if (street0.get(i) instanceof Market){
				lengthOfMarkets += street0.get(i).getLength();
				i += street0.get(i).getLength()-1;
			}
		}
		//Looking side 1 and adding market lengths
		for (int i = 0; i < getLength(); ++i){
			if (street1.get(i) instanceof Market){
				lengthOfMarkets += street1.get(i).getLength();
				i += street1.get(i).getLength()-1;
			}
		}
		return lengthOfMarkets;
	}

	/**
	 * 	Returns total length of houses in the street.
	 * 	@return total length of houses in the street
	 */
	public int houseLength(){
		int lengthOfHouses = 0;
		//Looking side 0 and adding house lengths
		for (int i = 0; i < getLength(); ++i){
			if (street0.get(i) instanceof House){
				lengthOfHouses += street0.get(i).getLength();
				i += street0.get(i).getLength()-1;
			}
		}
		//Looking side 1 and adding house lengths
		for (int i = 0; i < getLength(); ++i){
			if (street1.get(i) instanceof House){
				lengthOfHouses += street1.get(i).getLength();
				i += street1.get(i).getLength()-1;
			}
		}
		return lengthOfHouses;
	}

	/**
	 * 	Returns total length of offices in the street.
	 * 	@return total length of offices in the street
	 */
	public int officeLength(){
		int lengthOfOffices = 0;
		//Looking side 0 and adding office lengths
		for (int i = 0; i < getLength(); ++i){
			if (street0.get(i) instanceof Office){
				lengthOfOffices += street0.get(i).getLength();
				i += street0.get(i).getLength()-1;
			}
		}
		//Looking side 1 and adding office lengths
		for (int i = 0; i < getLength(); ++i){
			if (street1.get(i) instanceof Office){
				lengthOfOffices += street1.get(i).getLength();
				i += street1.get(i).getLength()-1;
			}
		}
		return lengthOfOffices;
	}

	/**
	 * 	Prints out the silhouette of the city.
	 */
	public void silhouette(){
		int maxHeight = 0;
		int maxHeightPosition = 0;
		int maxHeightSide = 0;
		int tempCol = 0;
		int firstCol=0, firstRow=0;
		boolean isDrawEnd, isDrawLimit, isFree;

		//Finding building that has maximum height
	
		for (int j = 0; j < getLength(); ++j){
			if (street0.get(j) != null && street0.get(j).getHeight() > maxHeight){
				maxHeight = street0.get(j).getHeight();
				maxHeightPosition = j;
				maxHeightSide = 0;
			}
		}
		for (int j = 0; j < getLength(); ++j){
			if (street1.get(j) != null && street1.get(j).getHeight() > maxHeight){
				maxHeight = street1.get(j).getHeight();
				maxHeightPosition = j;
				maxHeightSide = 1;
			}
		}
		

		//If street is empty, just prints the floor
		if (maxHeight == 0){
			System.out.printf("\n\n\n\n\n");
			for (int i = 0; i < getLength(); ++i) System.out.printf("-");
			System.out.printf("\n");
			return;
		}
		ArrayList<Building> streetMaxHeight;
		if (maxHeightSide == 0) streetMaxHeight = (ArrayList<Building>)street0.clone();
		else streetMaxHeight = (ArrayList<Building>)street1.clone();

		//2D ArrayList that demonstrates the street (maxHeight x lengthOfTheStreet)
		ArrayList<ArrayList<Character>> cityArray = new ArrayList<ArrayList<Character>>();    
		
		for (int i = 0; i < streetMaxHeight.get(maxHeightPosition).getHeight(); ++i){
			for (int j = 0; j < getLength(); ++j){
				cityArray.add(new ArrayList<Character>(getLength()));
				cityArray.get(i).add(j,' ');
			}
		}

		//Adding roofs of the buildings to the ArrayList
		for (int i = 0; i < getLength(); ++i){
			if (street0.get(i) != null){
				if (street1.get(i) != null){
					if (street0.get(i).getHeight() > street1.get(i).getHeight()) 
						cityArray.get(streetMaxHeight.get(maxHeightPosition).getHeight() - street0.get(i).getHeight()).set(i, '-');
					else cityArray.get(streetMaxHeight.get(maxHeightPosition).getHeight() - street1.get(i).getHeight()).set(i, '-');
				}
				else cityArray.get(streetMaxHeight.get(maxHeightPosition).getHeight() - street0.get(i).getHeight()).set(i, '-');
			}
			else if (street1.get(i) != null)
				cityArray.get(streetMaxHeight.get(maxHeightPosition).getHeight() - street1.get(i).getHeight()).set(i, '-');
		}

		//Adding right edges of the buildings to the ArrayList
		for (int i = 0; i < streetMaxHeight.get(maxHeightPosition).getHeight(); ++i){
			for (int j = 0; j < getLength(); ++j){
				isDrawLimit = isDrawEnd = false;
				if (cityArray.get(i).get(j) == '-'){
					for (int k = 0; k < streetMaxHeight.get(maxHeightPosition).getHeight(); ++k){
						if (j != getLength()-1 && cityArray.get(k).get(j+1) == '-'){
							if (k == i) isDrawLimit = false;
							else { isDrawLimit = true; tempCol = k; }
							break;
						}
						if (k == streetMaxHeight.get(maxHeightPosition).getHeight()-1) isDrawEnd = true;
					}
					if (isDrawEnd)
						for (int l = i+1; l < streetMaxHeight.get(maxHeightPosition).getHeight(); ++l) cityArray.get(l).set(j, '|');
					if (isDrawLimit){
						if (i > tempCol){
							for (int l = tempCol+1; l < i; ++l) cityArray.get(l).set(j, '|');
						}
						else{
							for (int l = i+1; l < tempCol; ++l) cityArray.get(l).set(j, '|');
						}
					}
				}
			}
		}

		//Adding left edges of the buildings to the ArrayList
		for (int i = 0; i < streetMaxHeight.get(maxHeightPosition).getHeight(); ++i){
			for (int j = 0; j < getLength(); ++j){
				isFree = true;
				if (cityArray.get(i).get(j) == '-'){
					for (int k = 0; k < streetMaxHeight.get(maxHeightPosition).getHeight(); ++k)
						if (j > 0 && cityArray.get(k).get(j-1) == '-') isFree = false;
				}
				else isFree = false;
				if (isFree){
					for (int k = i+1; k < streetMaxHeight.get(maxHeightPosition).getHeight(); ++k)
						cityArray.get(k).set(j, '|');
				}
			}
		}
		
		//Making some arrangements
		for (int i = 0; i < streetMaxHeight.get(maxHeightPosition).getHeight(); ++i){
			for (int j = 0; j < getLength(); ++j){
				if (cityArray.get(i).get(j) == '|'){
					if (i > 0){
						if (cityArray.get(i-1).get(j) == ' ') cityArray.get(i-1).set(j, '-');
					}
					if (i != streetMaxHeight.get(maxHeightPosition).getHeight()-1){
						if (cityArray.get(i+1).get(j) == ' ') cityArray.get(i+1).set(j, '-');
					}
				}
			}
		}

		//Printing out the city silhouette
		for (int i = 0; i < streetMaxHeight.get(maxHeightPosition).getHeight(); ++i){
			for (int j = 0; j < getLength(); ++j)
				System.out.printf("%c", cityArray.get(i).get(j));
			System.out.printf("\n");
		}
		for (int i = 0; i < getLength(); ++i) System.out.printf("-");
		System.out.printf("\n");
	}

	/**
	 * 	Returns back the building at the specified location
	 * 	@param side side of the building
	 * 	@param position position of the building
	 * 	@return building at the specified location
	 * 	@throws Exception thrown if any unproper values, or empty space is seen
	 */
	public Building getBuilding(int side, int position) throws Exception{
		if (side != 0 && side != 1) throw new Exception("Unproper side.");
		if (position < 0 || position >= getLength()) throw new Exception("Unproper position.");
		if (side == 0){
			if (street0.get(position) == null) throw new Exception("That place is empty.");
		}
		else{
			if (street1.get(position) == null) throw new Exception("That place is empty.");
		}
		if (side == 0) return street0.get(position);
		return street1.get(position);
	}

	@Override
	/**
	 * 	Overridden string method.
	 * 	@return string to represent street
	 */
	public String toString(){
		return String.format("Street\n------\n%s\n%s\n", super.toString(), buildingsList());
	}

	@Override
	/**
	 * 	Overridden equals method
	 * 	@param obj object to compare
	 * 	@return boolean that indicates if the objects are equal
	 */
	public boolean equals(Object obj){
		StreetArrayList other = (StreetArrayList) obj;
		if (other.getLength() != getLength()) return false;
		else{
			for (int i = 0; i < getLength(); ++i){
				if (!other.street0.get(i).equals(street0.get(i))) return false;
				if (!other.street1.get(i).equals(street1.get(i))) return false;
			}
		}
		return true;
	}

	@Override
	/**
	 * 	Overridden clone method
	 * 	@return street that has been copied
	 */
	public StreetArrayList clone(){
		try{
			StreetArrayList copy = (StreetArrayList) super.clone();
			copy.street0 = (ArrayList<Building>)street0.clone();
			copy.street1 = (ArrayList<Building>)street1.clone();
			return copy;
		}
		catch(Exception e){
			return null;
		}
	} 
}