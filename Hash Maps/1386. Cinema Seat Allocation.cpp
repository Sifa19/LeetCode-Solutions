class Solution {
public:
	int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
		// Your code goes here

		map<int,vector<int>> reservedRows;

		for(auto seat:reservedSeats){
			//mapping each row as key and
			//the columns of each row as value(vector)
			reservedRows[seat[0]].push_back(seat[1]);
		}

		int emptyRowsGroups= (n - reservedRows.size() )*2;
		//n is total no of rows
		//reservedRows.size()  rows with reserved seats 
		//n - reservedRows.size() empty rows (or only corner seat reaserved)
         //(n - reservedRows.size() )*2 Each row can have maximum 2 groups

		 //finding the possible no of 4 person groups in mappings

		 int groupsInReservedRows=0;

		 for(auto seat: reservedRows){

			 vector<int> seatsBooked(11,0);

			 for(int x:seat.second){
				 //marking the seats which are booked for each row
				 seatsBooked[x]=1;
			 }

			 //for each row the possible 4-person groups can be in following columns
			 //2 , 3 , 4 , 5  or 6 , 7 , 8 , 9 
			 //or 4 , 5 , 6 , 7

			//  checking if 2 , 3 , 4 , 5  group is possible
			if(!seatsBooked[2] && !seatsBooked[3] && !seatsBooked[4] && !seatsBooked[5]){
				groupsInReservedRows++;

				//if we alread boooked 2,3,4,5
				//then we shouldnt be able to book 4,5,6,7
				seatsBooked[5]=1;
			}

			//  checking if 6 , 7 , 8 , 9  group is possible
			if(!seatsBooked[6] && !seatsBooked[7] && !seatsBooked[8] && !seatsBooked[9]){
				groupsInReservedRows++;

				//if we alread boooked 6 , 7 , 8 , 9 
				//then we shouldnt be able to book 4,5,6,7
				seatsBooked[6]=1;
			}

			//  checking if 4 , 5 , 6 , 7  group is possible
			if(!seatsBooked[4] && !seatsBooked[5] && !seatsBooked[6] && !seatsBooked[7]){
				groupsInReservedRows++;
			}
		 }

		 return (emptyRowsGroups+groupsInReservedRows);

	}
};
