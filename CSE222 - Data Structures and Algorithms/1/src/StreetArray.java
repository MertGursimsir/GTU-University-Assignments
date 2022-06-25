/**
 * <h1>STREET CONTAINER CLASS!</h1>
 * This class has 2D array to keep buildings for 2 sides of the street.
 * @author Mert Gürşimşir
 * @version 1.0 (March 6 2022)
 */

public class StreetArray extends City{
	private Building[][] street;

	@SuppressWarnings("unchecked") // for unchecked type warning.
	/**
	 *	Constructor of StreetArray with lengthValue.
	 * 	Assign array's length to parameter.
	 *  @param lengthValue give length to street 
	 */
	public StreetArray(int lengthValue) throws Exception{
		super(lengthValue);
		street = new Building[2][getLength()];
		for (int j = 0; j < getLength(); ++j)
			street[0][j] = street[1][j] = null;
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
        		street[building.getSide()][i] = new House(temp.getSide(), temp.getLength(), temp.getPosition(), temp.getHeight(),
															temp.getRoomNumber(), temp.getColor(), temp.getOwner());
        	}
        	else if (building instanceof Office){
        		Office temp = (Office) building;
        		street[building.getSide()][i] = new Office(temp.getSide(), temp.getLength(), temp.getPosition(), temp.getHeight(),
															temp.getJobType(), temp.getOwner());
        	}
        	else if (building instanceof Market){
        		Market temp = (Market) building;
        		street[building.getSide()][i] = new Market(temp.getSide(), temp.getLength(), temp.getPosition(), temp.getHeight(),
															temp.getOpeningTime(), temp.getClosingTime(), temp.getOwner());
        	}
        	else if (building instanceof Playground){
        		Playground temp = (Playground) building;
        		street[building.getSide()][i] = new Playground(temp.getSide(), temp.getLength(), temp.getPosition());
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
		if (street[side][position] == null) throw new Exception("Attempting to delete empty space.");
	
		int tempPosition = street[side][position].getPosition();
		int tempLength = street[side][position].getLength();
		for (int i = tempPosition, j = 0; j < tempLength; ++i, ++j)  street[side][i] = null;
	}

	/**
	 * 	To check if there is enough space for the building that will be added.
	 * 	@param building building to be added to street
	 * 	@return true if there is enough space, otherwise false
	 */
    public boolean isEmpty(Building building){
    	for(int i = building.getPosition(), j = 0; j < building.getLength(); ++i, ++j)
    		if (street[building.getSide()][i] != null) return false;
    	return true;
	}

	/**
	 * 	Returns the remaining empty lands.
	 * 	@return remaining lands in the street
	 */
	public int remainingLands(){
		int remainingLands = 0;
		for (int i = 0; i < getLength(); ++i){
			if (street[0][i] == null) remainingLands++;
			if (street[1][i] == null) remainingLands++;
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
			if (street[0][i] != null){
				list = list + street[0][i];
				i += street[0][i].getLength()-1;
				flag = false;
			}
		}
		if (flag) list = list + "\nThere is nothing on this side of the street\n";
		else flag = true;

		//Listing side 1
		list = list + "\nSIDE 1\n======\n";
		for (int i = 0; i < getLength(); ++i){
			if (street[1][i] != null){
				list = list + street[1][i];
				i += street[1][i].getLength()-1;
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
			if (street[0][i] instanceof Playground){
				numOfPg++;
				i += street[0][i].getLength()-1;
			}
		}
		//Looking side 1
		for (int i = 0; i < getLength(); ++i){
			if (street[1][i] instanceof Playground){
				numOfPg++;
				i += street[1][i].getLength()-1;
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
			if (street[0][i] instanceof Playground){
				playgroundLength += street[0][i].getLength();
				i += street[0][i].getLength()-1;
			}
		}
		//Looking side 1 and adding playground lengths
		for (int i = 0; i < getLength(); ++i){
			if (street[1][i] instanceof Playground){
				playgroundLength += street[1][i].getLength();
				i += street[1][i].getLength()-1;
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
			if (street[0][i] instanceof Market){
				lengthOfMarkets += street[0][i].getLength();
				i += street[0][i].getLength()-1;
			}
		}
		//Looking side 1 and adding market lengths
		for (int i = 0; i < getLength(); ++i){
			if (street[1][i] instanceof Market){
				lengthOfMarkets += street[1][i].getLength();
				i += street[1][i].getLength()-1;
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
			if (street[0][i] instanceof House){
				lengthOfHouses += street[0][i].getLength();
				i += street[0][i].getLength()-1;
			}
		}
		//Looking side 1 and adding house lengths
		for (int i = 0; i < getLength(); ++i){
			if (street[1][i] instanceof House){
				lengthOfHouses += street[1][i].getLength();
				i += street[1][i].getLength()-1;
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
			if (street[0][i] instanceof Office){
				lengthOfOffices += street[0][i].getLength();
				i += street[0][i].getLength()-1;
			}
		}
		//Looking side 1 and adding office lengths
		for (int i = 0; i < getLength(); ++i){
			if (street[1][i] instanceof Office){
				lengthOfOffices += street[1][i].getLength();
				i += street[1][i].getLength()-1;
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
		for (int i = 0; i < 2; ++i){
			for (int j = 0; j < getLength(); ++j){
				if (street[i][j] != null && street[i][j].getHeight() > maxHeight){
					maxHeight = street[i][j].getHeight();
					maxHeightPosition = j;
					maxHeightSide = i;
				}
			}
		}

		//If street is empty, just prints the floor
		if (maxHeight == 0){
			System.out.printf("\n\n\n\n\n");
			for (int i = 0; i < getLength(); ++i) System.out.printf("-");
			System.out.printf("\n");
			return;
		}

		//2D array that demonstrates the street (maxHeight x lengthOfTheStreet)
		char[][] cityArray = new char[street[maxHeightSide][maxHeightPosition].getHeight()][getLength()];
		for (int i = 0; i < street[maxHeightSide][maxHeightPosition].getHeight(); ++i)
			for (int j = 0; j < getLength(); ++j)
				cityArray[i][j] = ' ';

		//Adding roofs of the buildings to the array
		for (int i = 0; i < getLength(); ++i){
			if (street[0][i] != null){
				if (street[1][i] != null){
					if (street[0][i].getHeight() > street[1][i].getHeight()) 
						cityArray[street[maxHeightSide][maxHeightPosition].getHeight() - street[0][i].getHeight()][i] = '-';
					else cityArray[street[maxHeightSide][maxHeightPosition].getHeight() - street[1][i].getHeight()][i] = '-';
				}
				else cityArray[street[maxHeightSide][maxHeightPosition].getHeight() - street[0][i].getHeight()][i] = '-';
			}
			else if (street[1][i] != null)
				cityArray[street[maxHeightSide][maxHeightPosition].getHeight() - street[1][i].getHeight()][i] = '-';
		}

		//Adding right edges of the buildings to the array
		for (int i = 0; i < street[maxHeightSide][maxHeightPosition].getHeight(); ++i){
			for (int j = 0; j < getLength(); ++j){
				isDrawLimit = isDrawEnd = false;
				if (cityArray[i][j] == '-'){
					for (int k = 0; k < street[maxHeightSide][maxHeightPosition].getHeight(); ++k){
						if (j != getLength()-1 && cityArray[k][j+1] == '-'){
							if (k == i) isDrawLimit = false;
							else { isDrawLimit = true; tempCol = k; }
							break;
						}
						if (k == street[maxHeightSide][maxHeightPosition].getHeight()-1) isDrawEnd = true;
					}
					if (isDrawEnd)
						for (int l = i+1; l < street[maxHeightSide][maxHeightPosition].getHeight(); ++l) cityArray[l][j] = '|';
					if (isDrawLimit){
						if (i > tempCol){
							for (int l = tempCol+1; l < i; ++l) cityArray[l][j] = '|';
						}
						else{
							for (int l = i+1; l < tempCol; ++l) cityArray[l][j] = '|';
						}
					}
				}
			}
		}

		//Adding left edges of the buildings to the array
		for (int i = 0; i < street[maxHeightSide][maxHeightPosition].getHeight(); ++i){
			for (int j = 0; j < getLength(); ++j){
				isFree = true;
				if (cityArray[i][j] == '-'){
					for (int k = 0; k < street[maxHeightSide][maxHeightPosition].getHeight(); ++k)
						if (j > 0 && cityArray[k][j-1] == '-') isFree = false;
				}
				else isFree = false;
				if (isFree){
					for (int k = i+1; k < street[maxHeightSide][maxHeightPosition].getHeight(); ++k)
						cityArray[k][j] = '|';
				}
			}
		}
		
		//Making some arrangements
		for (int i = 0; i < street[maxHeightSide][maxHeightPosition].getHeight(); ++i){
			for (int j = 0; j < getLength(); ++j){
				if (cityArray[i][j] == '|'){
					if (i > 0){
						if (cityArray[i-1][j] == ' ') cityArray[i-1][j] = '-';
					}
					if (i != street[maxHeightSide][maxHeightPosition].getHeight()-1){
						if (cityArray[i+1][j] == ' ') cityArray[i+1][j] = '-';
					}
				}
			}
		}

		//Printing out the city silhouette
		for (int i = 0; i < street[maxHeightSide][maxHeightPosition].getHeight(); ++i){
			for (int j = 0; j < getLength(); ++j)
				System.out.printf("%c", cityArray[i][j]);
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
		if (street[side][position] == null) throw new Exception("That place is empty.");
		return street[side][position];
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
		StreetArray other = (StreetArray) obj;
		if (other.getLength() != getLength()) return false;
		else{
			for (int i = 0; i < getLength(); ++i){
				if (!other.street[0][i].equals(street[0][i])) return false;
				if (!other.street[1][i].equals(street[1][i])) return false;
			}
		}
		return true;
	}

	@Override
	/**
	 * 	Overridden clone method
	 * 	@return street that has been copied
	 */
	public StreetArray clone(){
		try{
			StreetArray copy = (StreetArray) super.clone();
			copy.street = new Building[2][getLength()];
			for (int i = 0; i < 2; ++i){
				for (int j = 0; j < getLength(); ++j){
					copy.street[i][j] = street[i][j].clone();
				}
			}
			return copy;
		}
		catch(Exception e){
			return null;
		}
	} 
}