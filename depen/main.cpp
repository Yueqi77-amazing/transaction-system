#include <iostream>

#include <vector>
#include <queue>
#include <sstream>


using namespace std;
vector<int> haveCircularDependency(int n, vector<vector<int>> prerequisites)
{
    //to see if the current node has the enter edge.
    vector<int> enteringEdge(n, 0);
    //To mimic a sheet that contains all the conections bet the different nodes.
    vector<vector<int>> LinkList(n);
    //To store the final result
    vector<int> res;
    //record the node with no enter edge.
    queue<int> q;
    //create the connection sheet
    for (int i = 0; i < prerequisites.size(); ++i)
    {
        LinkList[prerequisites[i][0]].push_back(prerequisites[i][1]);//update the connection sheet
        enteringEdge[prerequisites[i][1]] ++;//enter edge +1
    }
    //To find nodes with no enter edge
    for (int i = 0; i < enteringEdge.size(); ++i)
    {
        if (enteringEdge[i] == 0)
            q.push(i);
    }
    int size = q.size();
    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        res.push_back(index);

        for (int i = 0; i < LinkList[index].size(); ++i)
        {
            //LinkList[index] stores all the node that connect to the index.
            enteringEdge[LinkList[index][i]] --;//update the enter edge of other nodes
            if (enteringEdge[LinkList[index][i]] == 0)
            {
                size++;
                q.push(LinkList[index][i]);//push into q list
            }
        }
    }
    if (size != n)
    {
        cout << "False" << endl;
    }else{
        cout << "True" << endl;
    }
    return res;
}
//To find out if x contained in the vector.
bool contains(vector<char> v, char x)
{
    if (v.empty())
        return false;
    if (find(v.begin(), v.end(), x) != v.end())
        return true;
    else
        return false;
}
vector<int> dependence(){
    //input the code. w1x...
    string  str,temp;
    getline(cin, str);
    int  i = 0;
    int size=str.length();
    vector < char > p;
    stringstream  input(str);
    while (input >> i){
        p.push_back(i);
    }
    vector<vector<int>> vec;
    vector<char> elements;//to store the size of the nodes(processes).
    for(int temp=0; temp < size; temp+=3)//double while to check if there is a conflict exists.
    {
        char wr=str[temp];
        char num = str[temp+1];

        char xy=str[temp+2];
        if(contains(elements,num)== false){
            elements.push_back(num);
        }
        for(int j =temp+4;j<size;j+=3){
            if(num!=str[j]&&(wr=='w'||str[j-1]=='w')&&xy==str[j+1]) {
                vector<int> a;
                a.push_back(num-49);//to change the char to the int
                a.push_back(str[j]-49);
                vec.push_back(a);
            }

        }
        int i,j;
        //This part is to output the conflict.
      //  cout << "Use index : " << endl;
//        for (i = 0; i < vec.size(); i++)
//        {
//            for(j = 0; j < vec[0].size(); j++)
//                cout << vec[i][j] << " ";
//            cout << endl;
//        }
//        printf("%c xunhuan\n",str[temp+1]);
    }
    //cout << "size = " << elements.size() << endl;

    vector<int> re = haveCircularDependency(elements.size(),vec);
    return re;
}



int main()
{
    vector<int> res =dependence();
    return 0;
}
