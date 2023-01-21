package dayofyearsetpackage;
import java.util.ArrayList;

/**
 * <h1>DAYS OF THE YEAR!</h1>
 * Each DayofYearSet objects has DayofYear array inside it.
 * DayofYear is inner class that has day and month value.
 * @author Mert Gürşimşir
 * @version 1.0 (January 6 2022)
 */

public class DayofYearSet{
	/** Inner class DayofYear */
	public static class DayofYear{
		/** 
		 * No parameter constructor of inner class. 
		 * Assign day and month to 1
		 */
		public DayofYear(){
			day = 1;
			month = 1;
		}

		/** 
		 * Constructor of inner class with day value. 
		 * Assign day to given parameter and month to 1
		 */
		public DayofYear(int dayValue){
			if (dayValue < 1 || dayValue > 31){
				System.out.println("Invalid day value. \"1\" will be used as day.");
				day = 1;
			}
			else day = dayValue;
			month = 1;
		}

		/** 
		 * Constructor of inner class with day and month values. 
		 * Assign day and month to given parameters
		 */
		public DayofYear(int dayValue, int monthValue){
			if (monthValue < 1 || monthValue > 12){
				System.out.println("Invalid value for date. \"1.1\" is going to be used for date.\n");
				day = 1;
				month = 1;
			}
			else{
				month = monthValue;
				switch(monthValue){
					case 1: if(dayValue < 1 || dayValue > 31){
								System.out.println("Invalid day value. \"1\" will be used as the day.\n");
								day = 1;
							}
							else day = dayValue;
							break;
					case 2: if(dayValue < 1 || dayValue > 29){
								System.out.println("Invalid day value. \"1\" will be used as the day.\n");
								day = 1;
							}
							else day = dayValue;
							break;
					case 3: if(dayValue < 1 || dayValue > 31){
								System.out.println("Invalid day value. \"1\" will be used as the day.\n");
								day = 1;
							}
							else day = dayValue;
							break;
					case 4: if(dayValue < 1 || dayValue > 30){
								System.out.println("Invalid day value. \"1\" will be used as the day.\n");
								day = 1;
							}
							else day = dayValue;
							break;
					case 5: if(dayValue < 1 || dayValue > 31){
								System.out.println("Invalid day value. \"1\" will be used as the day.\n");
								day = 1;
							}
							else day = dayValue;
							break;
					case 6: if(dayValue < 1 || dayValue > 30){
								System.out.println("Invalid day value. \"1\" will be used as the day.\n");
								day = 1;
							}
							else day = dayValue;
							break;
					case 7: if(dayValue < 1 || dayValue > 31){
								System.out.println("Invalid day value. \"1\" will be used as the day.\n");
								day = 1;
							}
							else day = dayValue;
							break;
					case 8: if(dayValue < 1 || dayValue > 31){
								System.out.println("Invalid day value. \"1\" will be used as the day.\n");
								day = 1;
							}
							else day = dayValue;
							break;
					case 9: if(dayValue < 1 || dayValue > 30){
								System.out.println("Invalid day value. \"1\" will be used as the day.\n");
								day = 1;
							}
							else day = dayValue;
							break;
					case 10:if(dayValue < 1 || dayValue > 31){
								System.out.println("Invalid day value. \"1\" will be used as the day.\n");
								day = 1;
							}
							else day = dayValue;
							break;
					case 11:if(dayValue < 1 || dayValue > 30){
								System.out.println("Invalid day value. \"1\" will be used as the day.\n");
								day = 1;
							}
							else day = dayValue;
							break;
					case 12:if(dayValue < 1 || dayValue > 31){
								System.out.println("Invalid day value. \"1\" will be used as the day.\n");
								day = 1;
							}
							else day = dayValue;
							break;
				}
			}
		}

		/** 
		 * Getter for the day
		 * @return day of the year
		*/
		public final int getDay() {
			return day;
		}

		/**
		 * Getter for the month
		 * @return month of the year
		*/
		public final int getMonth() {
			return month;
		}

		/**
		 * Setter for the day
		 * @param dayValue the value of the day to be set
		*/
		public void setDay(int dayValue) {
			day = dayValue;
		}

		/**
		 * Setter for the month
		 * @param monthValue the value of the month to be set
		*/
		public void setMonth(int monthValue) {
			month = monthValue;
		}	


		private int day;
		private int month;
	}


	private DayofYear[] dates;
	private int used;
	private int capacity;
	static int objectCount = 0;

	/** 
	 * No parameter constructor of the set. 
	 * Creates set for 50 elements
	 */
	public DayofYearSet(){
		used = 0;
		capacity = 50;
		dates = new DayofYear[capacity];
	}
	/**
	 * 1 parameter constructor of the set. 
	 * Creates set for given number of elements
	 */
	public DayofYearSet(int capacityValue){
		used = 0;
		capacity = capacityValue;
		dates = new DayofYear[capacity];
	}
	/**
	 * 1 parameter constructor of the set. 
	 * Takes an ArrayList of DayofYear objects
	 */
	public DayofYearSet(ArrayList<DayofYear> datesArray){
		capacity = 50;
		dates = new DayofYear[capacity];
		for (int i = 0; i < datesArray.size(); ++i)
			add(datesArray.get(i));
	}
	/**
	 * Overridden toString method to convert set objects to String
	 */
	public String toString(){
		String temp;
		temp = String.format("\nCapacity: %d\nNumber of dates: %d\nDATES\n-----\n", capacity, used);

		for (int i = 0; i < used; ++i){
			switch(dates[i].getMonth()){
				case 1: temp += String.format("%d January\n\n", dates[i].getDay()); break;
				case 2: temp += String.format("%d February\n\n", dates[i].getDay()); break;
				case 3: temp += String.format("%d March\n\n", dates[i].getDay()); break;
				case 4: temp += String.format("%d April\n\n", dates[i].getDay()); break;
				case 5: temp += String.format("%d May\n\n", dates[i].getDay()); break;
				case 6: temp += String.format("%d June\n\n", dates[i].getDay()); break;
				case 7: temp += String.format("%d July\n\n", dates[i].getDay()); break;
				case 8: temp += String.format("%d August\n\n", dates[i].getDay()); break;
				case 9: temp += String.format("%d September\n\n", dates[i].getDay()); break;
				case 10:temp += String.format("%d October\n\n", dates[i].getDay()); break;
				case 11:temp += String.format("%d November\n\n", dates[i].getDay()); break;
				case 12:temp += String.format("%d December\n\n", dates[i].getDay()); break;
			}
		}
		return temp;
	}
	/**
	 * Overridden equals method comparing set objects.
	 * @param other Another DayofYearSet object to compare
	 * @return boolean Returns true if two sets are equal, otherwise false
	 */
	public boolean equals(DayofYearSet other){
		var flag = true;
		int j;
		if (used != other.used) flag = false; //They are not equal if their size are not equal.
		else{
			for (int i = 0; i < used; ++i){
				for (j = 0 ; j < used; ++j){
					if(dates[i].getDay() == other.dates[j].getDay() && dates[i].getMonth() == other.dates[j].getMonth()) break;
					//Comparing if the element in left-hand-side set exists in the right-hand-side set
				}
				if (j == used){
					flag = false;
					break;
				}
			}
		}
		return flag;
	}
	/**
	 * Method to add element to set.
	 * @param date DayofYear object to be added to set.
	 */
	public void add(DayofYear date){
		for (int i = 0; i < used; ++i){
			if (date.getDay() == dates[i].getDay() && date.getMonth() == dates[i].getMonth()){
				return;
			}
			//The element which already exists in set shouldn't be added
		}

		//check if we have enough space, if not allocate new memory
		if (used >= capacity){
			capacity *= 2; //incrementing the capacity
			DayofYear[] temp = new DayofYear[capacity];	//allocate more memory
			for(int i = 0; i < used; ++i){
				temp[i] = new DayofYear(dates[i].getDay(), dates[i].getMonth());
			}
			dates = temp;
		}

		dates[used] = new DayofYear(date.getDay(), date.getMonth());
		used++;
		objectCount++;
	}
	/**
	 * Method to remove element from set.
	 * @param index int value to specify element to be removed.
	 * @exception Exception on out of index error
	 */
	public void remove(int index) throws Exception{
		if (index >= used || index < 0){
			//checking if index value proper
			throw new Exception();
			//System.out.println("Illegal index!");
			//System.exit(0);
		}
		for(int i = index; i < used-1; ++i){
			//slide every value by one
			dates[i] = dates[i+1];
		}
		used--;
		objectCount--;
	}
	/**
	 * Method to return number of elements in the array.
	 * @return int number of elements
	 */
	public final int size(){
		return used;
	}
	/**
	 * Method to combine to sets
	 * @param other DayofYearSet to be united
	 * @return DayofYearSet
	 */
	public final DayofYearSet union(final DayofYearSet other){
		DayofYearSet temp = new DayofYearSet();
		var flag = true;
		
		for (int i = 0; i < size(); ++i){
			temp.add(dates[i]); //add all elements in our set
		}

		for (int i = 0; i < other.size(); ++i){
			flag = true;
			for(int j = 0; j < temp.size(); ++j){
				if (other.dates[i].getDay() == temp.dates[j].getDay() && other.dates[i].getMonth() == temp.dates[j].getMonth()){ 
					flag = false; break; 
					//skipping same elements
				}
			}
			if (flag == true) temp.add(other.dates[i]);
			//adding different elements
		}
		objectCount -= temp.size();

		return temp;
	}
	/**
	 * Method to find difference of 2 sets
	 * @param other DayofYearSet to find the difference from
	 * @return DayofYearSet
	 */
	public final DayofYearSet difference(final DayofYearSet other){
		DayofYearSet temp = new DayofYearSet();
		var flag = true;

		for (int i = 0; i < size(); ++i){
			flag = true;
			for (int j = 0; j < other.size(); ++j){
				if (dates[i].getDay() == other.dates[j].getDay() && dates[i].getMonth() == other.dates[j].getMonth()){
					flag = false; break;
					//skipping same elements
				}
			}
			if (flag == true) temp.add(dates[i]);
			//adding different elements
		}
		objectCount -= temp.size();
		return temp;
	}
	/**
	 * Method to find intersection of 2 sets
	 * @param other DayofYearSet to find intersection with
	 * @return DayofYearSet
	 */
	public final DayofYearSet intersection(final DayofYearSet other){
		DayofYearSet temp = new DayofYearSet();

		for (int i = 0; i < size(); ++i){
			for (int j = 0; j < other.size(); ++j){
				if (dates[i].getDay() == other.dates[j].getDay() && dates[i].getMonth() == other.dates[j].getMonth())
					temp.add(dates[i]);
				//adding same elements
			}
		}
		objectCount -= temp.size();
		return temp;
	}
	/**
	 * Method to find complement of the set
	 * @return DayofYearSet
	 */
	public final DayofYearSet complement(){
		DayofYearSet temp = new DayofYearSet();
		var flag = true;

		for (int i = 1; i < 13; ++i){
			switch(i){
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:for (int j = 1; j < 32; ++j){
							flag = true;
							for (int k = 0; k < size(); ++k){
								if (dates[k].getDay() == j && dates[k].getMonth() == i){
									flag = false;
									break;
								}
							}
							if (flag == true) {
								temp.add(new DayofYear(j,i));
							}
						}
						break;
						//Checking if date exists in the set for January, March, May, July, August, October, December. If not --> add
				case 2:	for (int j = 1; j < 30; ++j){
							flag = true;
							for (int k = 0; k < size(); ++k){
								if (dates[k].getDay() == j && dates[k].getMonth() == 2){
									flag = false;
									break;
								}
							}
							if (flag == true) {
								temp.add(new DayofYear(j,i));
							}
						}
						break;
						//Checking if date exists in the set for February. If not --> add
				case 4: 
				case 6:
				case 9:
				case 11:for (int j = 1; j < 31; ++j){
							flag = true;
							for (int k = 0; k < size(); ++k){
								if (dates[k].getDay() == j && dates[k].getMonth() == i){
									flag = false;
									break;
								}
							}
							if (flag == true) {
								temp.add(new DayofYear(j,i));
							}
						}
						break;
						//Checking if date exists in the set for April, June, September, November. If not --> add
			}
		}
		objectCount -= temp.size();
		return temp;
	}
	/**
	 * Static method that returns the total number of DayofYear objects alive in all the sets.
	 * @return int number of objects
	 */
	public static int aliveObjects(){
		return objectCount;
	}	
}