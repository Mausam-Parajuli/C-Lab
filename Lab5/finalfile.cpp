#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Library{
	private:
		string ISBN , title , author ;
		int numOfCopies;
	public:
		void getdata(){
			cout<<"Enter the Book Details :"<<endl;
			cout<<"ISBN :\t";
			getline(cin , ISBN);
			cout<<"Title:\t";
			getline(cin , title);
			cout<<"Author:\t";
			getline(cin , author);
			cout<<"No of Copies:\t";
			cin>>numOfCopies;
			cin.ignore();
		};
		void showdata(){
			cout<<"ISBN:\t"<<ISBN<<endl<<"Title:\t"<<title<<endl<<"Author:\t"<<author<<endl<<"No of copies:\t"<<numOfCopies<<endl;
		};
		void addToFile(ofstream &file){
			file << ISBN << endl << title << endl << author << endl << numOfCopies <<endl;
		};
		void readFromFile(ifstream &File){
			getline(File , ISBN);
			getline(File , title);
			getline(File , author);
			File >> numOfCopies;
			File.ignore();
		};
		void update(int no , string issueOrReturn){
			if(issueOrReturn == "issue"){
				numOfCopies -= no;
			}
			if(issueOrReturn == "return"){
				numOfCopies += no;
			}
		};
		void updateBook(Library a){
			ISBN = a.ISBN;
			title = a.title;
			author = a.author;
			numOfCopies = a.numOfCopies;
		};
		void add(int &count){
			ifstream file("Library_books.txt",ios::binary );
			if(!file){
				ofstream newFile("Library_books.txt",ios::app);
				addToFile(newFile);
				count++;
				newFile.close();
			}
			else{
				Library kitab;
				while(!file.eof()){
						kitab.readFromFile(file);
						if(ISBN == kitab.ISBN){
							cout<<"Book with the same ISBN already exists .";
							file.close();
							break;
						}
						else{
							file.close();
							ofstream file("Library_books.txt",ios::app);
							addToFile(file);
							cout<<"Book added sucessfully."<<endl;
							file.close();
							break;
						}
				}
			}
			
		/*	books[].getdata();
			Library temp;
			count++;
			ifstream filein("Library_books.txt");
			if(!filein){
				ofstream file("Library_books.txt");
				file<<books[count].ISBN<<"\t"<<books[count].title<<"\t"<<books[count].author<<"\t"<<books[count].numOfCopies<<endl;
				cout<<"Book added .";
				return;
			}
			else{
				while(!filein.eof()){
					filein.read((char*)&temp , sizeof(temp));
					if(temp.ISBN == books[count].ISBN){
						cout<<"ISBN must be unique .";
						filein.close();
					}
					else{
						ofstream file("Library_books.txt");
						file << books[count].ISBN<<"\t"<<books[count].title<<"\t"<<books[count].author<<"\t"<<books[count].numOfCopies<<endl;
						file.close();
					}
			    }
			}
			filein.close();*/
		};
		static void issueBooks(string isbn , int no ){
			Library temp[100];
			ifstream file;
			file.open("Library_books.txt");
			int totalbooks = 0;
			bool found = false;
			ofstream fileIssue("temp.txt",ios::app);
			while(!file.eof()){
				temp[totalbooks].readFromFile(file);
				if(temp[totalbooks].ISBN == isbn){
					temp[totalbooks].update(no , "issue");
					found = true;
				}
			//	temp[totalbooks].addToFile(fileIssue);
				totalbooks++;
			}
			for(int i=0; i<(totalbooks - 1); i++){
				temp[i].addToFile(fileIssue);
			}
			if(!found){
				cout<<"Book not found.";
			}
			file.close();
			fileIssue.close();
			remove("Library_books.txt");
			rename("temp.txt" , "Library_books.txt");
		};
		static void returnBooks(string isbn , int no){
			Library temp[100];
			ifstream file;
			file.open("Library_books.txt");
			int totalbooks = 0;
			bool found = false;
			ofstream fileReturn("temp.txt",ios::app);
			while(!file.eof()){
				temp[totalbooks].readFromFile(file);
				if(temp[totalbooks].ISBN == isbn){
					temp[totalbooks].update(no , "return");
					found = true;
				}
				totalbooks++;
			}
			for(int i=0; i<(totalbooks-1); i++){
				temp[i].addToFile(fileReturn);
			}
			if(!found){
				cout<<"Book not found.";
			}
			file.close();
			fileReturn.close();
			remove("Library_books.txt");
			rename("temp.txt", "Library_books.txt");
		};
		static void updateDetails(string isbn){
			Library temp[100] , fodder;
			ifstream file("Library_books.txt");
			int totalbooks = 0;
			ofstream fileUpdate("temp.txt",ios::app);
			bool found = false;
			while(!file.eof()){
				temp[totalbooks].readFromFile(file);
				if(temp[totalbooks].ISBN == isbn){
					fodder.getdata();
					temp[totalbooks].updateBook(fodder);
					found = true;
				}
				totalbooks++;
			}
			for(int i=0; i<(totalbooks-1); i++){
				temp[i].addToFile(fileUpdate);
			}
			if(!found){
				cout<<"Book with that ISBN not found .";
			}
			file.close();
			fileUpdate.close();
			remove("Library_books.txt");
			rename("temp.txt","Library_books.txt");
		};
		static void deleteBook(string isbn){
			Library temp[100];
			ifstream file("Library_books.txt");
			int totalbooks = 0;
			bool found = false ;
			ofstream fileDelete("temp.txt",ios::app);
			while(!file.eof()){
				temp[totalbooks].readFromFile(file);
				if(temp[totalbooks].ISBN == isbn){
					found = true;
				}
				else{
					totalbooks++;
				}
			}
			for(int i=0;i<(totalbooks-1);i++){
					temp[i].addToFile(fileDelete);
			}
			if(!found){
				cout<<"Book not found in the library.";
			}
			file.close();
			fileDelete.close();
			remove("Library_books.txt");
			rename("temp.txt","Library_books.txt");
			
		}
		static void showAllBooks(){
			Library temp[100];
			ifstream file;
			file.open("Library_books.txt ");
			int totalbooks = 0;
			while(!file.eof()){
				temp[totalbooks].readFromFile(file);
				totalbooks++;
			}
			for(int i=0;i<(totalbooks-1);i++){ 
				temp[i].showdata();
				cout<<"________________________"<<endl;
			}
			 
			file.close();
			
		};
};

int main(){
	Library books[100];
	int num, hold = 1,count = 0 ,no;
	string isbn;
 	do{
	cout<<"Enter a number to proceed:"<<endl<<endl;
	cout<<"1.Add book\n"<<"2.Issue book"<<endl<<"3.Return book"<<endl<<"4.Update book"<<endl<<"5.Delete book"<<endl<<"6.View catalogue"<<endl<<"7.Exit"<<endl;
	cin>>num;
	cin.ignore();
	switch(num){
		case 1:
			books[count].getdata();
			books[count].add(count);
			break;
		case 2:
			cout<<"Enter the ISBN:";
			getline(cin,isbn);
			cout<<"Enter no of copies to issue:";
			cin>>no;
			cin.ignore();
			Library::issueBooks(isbn,no);
			break;
		case 3:
			cout<<"Enter the ISBN:";
			getline(cin,isbn);
			cout<<"Enter no of copies to return:";
			cin>>no;
			cin.ignore();
			Library::returnBooks(isbn,no);
			break;
		case 4:
			cout<<"Enter the ISBN:";
			getline(cin,isbn);
			Library::updateDetails(isbn);
			break;
		case 5:
			cout<<"Enter the ISBN:";
			getline(cin,isbn);
			Library::deleteBook(isbn);
			break;
		case 6:
			Library::showAllBooks();
			break;
		case 7:
			hold = 0;
			break;
		default:
			cout<<"Invalid input";
			break;
	}
	
	
	}
	while(hold=1);
 
/*	books[count].getdata();
	books[count].add(count);
	Library::showAllBooks(); 
    cout<<"Enter the ISBN :";
    getline(cin , isbn);
//    cout<<"Enter no of copies to return :";
//    cin>>num;
//    Library::issueBooks( isbn , num);
//    Library::showAllBooks(); 
//	Library::returnBooks(isbn , num);
//	Library::updateDetails(isbn);
	Library::deleteBook(isbn);
	Library::showAllBooks(); */
	return 0;
}
