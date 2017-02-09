#include <map>
#include <vector>
#include <iostream>

using namespace std;  

class Node 
{
    public:
    string name ;  
    Node *next ;   
    Node (string n1)
    {
        name = n1 ;  
        next = NULL ;
    } 
    Node(){}
    ~Node(){}
};

class AdjList 
{
    public:
    Node *head ; 
    int degree ;    
    AdjList()
    {
        head = NULL ; 
    } 

    ~AdjList(){} 

    void Print()
    {
        for ( Node *h = head ; h != NULL ; h = h->next )
        {
            cout << h->name << " " ;
        } 
        cout << " " ;
        cout << "DEGREE: " << degree << endl; 
        cout << endl; 
    }
};

void PrintNodes ( map < string ,Node* > allNodes )
{
    for ( auto it = allNodes.begin() ; it != allNodes.end() ; it++ )
    {
        Node *n1 = it -> second ; 
        cout << n1->name << endl;
    }
}

void PrintGraph ( map< string , AdjList* >  graph )
{
    cout << "************************* PRINTING GRAPH *****************************" << endl;


    for ( auto it = graph.begin() ; it != graph.end() ; it++ )
    { 
        cout << "NODE CONNECTED TO: " << it -> first << "  ARE: " ;
        AdjList *a1 = it -> second ;
        a1->Print(); 
    } 

}


void getMax ( AdjList &a1 , AdjList &a2 , vector < pair < AdjList* , AdjList* > > q )
{
    int max= -1 ;
        
    for ( int i =0 ; i < q.size() ; i++ )
    {
        AdjList *t1 = q[i].first; 
        AdjList *t2 = q[i].second ; 
        
        int sum = t1->degree+ t2->degree ;

        if ( sum > max )
        {
            a1 = t1 ; 
            a2 = t2 ; 
            max = sum ;
        }
    } 
}

int main()
{
    vector < string > givenNodes; 
    givenNodes.push_back ( "A"); 
    givenNodes.push_back ( "B");
    givenNodes.push_back ( "C");
    givenNodes.push_back ( "D");
    givenNodes.push_back ( "E");
    givenNodes.push_back ( "F");

    map< string , Node* >  allNodes ; 

    for ( int i =0 ; i < givenNodes.size() ; i++ )
    {
        Node *n1 = new Node ( givenNodes[i] ) ; 
        allNodes[givenNodes[i]] = n1;        
    }  

    PrintNodes ( allNodes ) ; 



    map < string , AdjList* > Graph ; 


    for ( int i = 0 ; i< givenNodes.size(); i++ )
    {
        AdjList *e1 = new AdjList();    
        Graph[ givenNodes[i] ] = e1; 
    } 

    PrintGraph ( Graph ) ;



    vector < pair < string , string > > givenEdges; 
   
    givenEdges.push_back ( make_pair ("A" ,"B" ) ); 
    givenEdges.push_back ( make_pair ("A" ,"C" ) );
    givenEdges.push_back ( make_pair ("B" ,"E" ) );
    givenEdges.push_back ( make_pair ("B" , "D") );
    givenEdges.push_back ( make_pair ("E" ,"D" ) );
    givenEdges.push_back ( make_pair ("D" ,"C" ) );
    givenEdges.push_back ( make_pair ("D" ,"F" ) );
    givenEdges.push_back ( make_pair ("C" ,"F" ) );
        


    for ( int i = 0 ; i < givenEdges.size() ; i++ )
    {
        Node *n1 = new Node ( givenEdges[i].second ) ;  
        n1 -> next = ( Graph[givenEdges[i].first])->head;    
        (Graph[ givenEdges[i].first ])->head = n1 ;   


        
        Node *n2 = new Node ( givenEdges[i].first ) ;
        n2 -> next = ( Graph[ givenEdges[i].second ]) -> head ;
        (Graph[ givenEdges[i].second ]) -> head = n2 ; 


    } 


    Graph["A" ]->degree = 2 ; 
    Graph["B" ]->degree = 3 ;
    Graph["C" ]->degree = 3 ;
    Graph["D" ]->degree = 4 ;
    Graph["E" ]->degree = 2 ;
    Graph["F" ]->degree = 3 ; 


    vector < pair < AdjList* , AdjList* > > q ;  

    vector < AdjList* > s; 

    for ( auto it = Graph.begin() ; it != Graph.end() ; it ++ )
    {
        string n1 = it -> first ;
        AdjList *a1 = it -> second; 
        for ( Node *h = a1->head ; h != NULL ; h = h->next )  
        {
            AdjList *f1 = Graph[n1]; 
            AdjList *f2 = Graph[h->name]; 

            q.push_back( make_pair( f1 , f2 ) ) ;
        }
        
    }    


    while ( q.size() > 0 )
    {
        if ( s.size() == 0 )
        {
            AdjList *a1, *a2 ;
            getMax ( a1, a2 , q ); 
        }
        else 
        {
            
        }

        
    }

    PrintGraph ( Graph ) ;
  
   return 0 ; 
}

