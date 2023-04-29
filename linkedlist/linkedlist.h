typedef struct t_list_node{
    string data;
    struct t_list_node *link;
}   list_node;

class SList
{
    private:
        list_node *head;

    public:
        SList();
        ~SList();
        bool Retrieve(char data); //return false if not found
        list_node* Retrieve(int index);
        void Insert(char data);
        void Delete(char data);
        void Invert();
        void Print();
        bool IsEmpty();
        int Get_Len();
}