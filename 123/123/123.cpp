
 
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stack>
 
typedef std::vector<std::vector<int> > VM;
typedef std::stack<int> ST;
 
class MatrixAdj
{
public:
    MatrixAdj()
    {
    }
 
    virtual ~MatrixAdj()
    {
    }
 
    void SetSize(const size_t n)
    {
        Matr.resize(n);
        for(size_t i=0; i<n; ++i)
            Matr[i].resize(n);
    }
 
    void Fill()
    {
        for(size_t i=0; i<Matr.size(); ++i)
        {
            for(size_t j=0; j<Matr.size(); ++j)
            {
                if(i==j)
                    Matr[i][j]=0;
                else if(i>j)
                {
                    Matr[i][j]=Matr[j][i];
                }
                else
                {
                    std::cout<<"Enter weight of V"<< i <<",V"<< j <<" edge\n"
                        <<"0 for not connect them\n";
                    std::cin>>Matr[i][j];
                    if(Matr[i][j]==0)
                        Matr[i][j]=100;
                }
            }
        }
    }
protected:
    VM Matr;
};
 
class Floyd:public MatrixAdj
{
public:
    Floyd():MatrixAdj()
    {
    }
 
    ~Floyd()
    {
    }
 
    void Initialise()
    {
        MatrPath.resize(Matr.size());
        for(size_t i=0; i<Matr.size(); ++i)
            MatrPath[i].resize(Matr.size());
        for(size_t i=0; i<MatrPath.size(); ++i)
        {
            for(size_t j=0; j<MatrPath.size(); ++j)
            {
                if(Matr[i][j]==100)
                    MatrPath[i][j]=100;
                else
                    MatrPath[i][j]=j;
            }
        }
        Copy();
    }
    
    void FindPathMatr()
    {
        for(size_t k=0; k<Matr.size(); ++k)
        {
            for(size_t i=0; i<Matr.size(); ++i)
            {
                for(size_t j=0; j<Matr.size(); ++j)
                {
                    int b=MatrSPath[i][k]+MatrSPath[k][j];
                    if(b<MatrSPath[i][j])
                    {
                        MatrSPath[i][j]=b;
                        MatrPath[i][j]=k;
                    }
                }
            }
        }
    }
 
    void FindPath(size_t first, size_t second)
    {
        if(first>=MatrPath.size() || second>=MatrPath.size())
            throw std::invalid_argument("One of nodes for searching is more than Matr size");
        ST Goals;
        Path.push(first);
        Goals.push(second);
        while(!Goals.empty())
        {
            int u=Path.top();
            int v=Goals.top();
            int s=MatrPath[u][v];
            if(v==s)
            {
                Path.push(v);
                Goals.pop();
            }
            else
                Goals.push(s);
        }
    }
 
    void PrintWMatr(std::ostream& os) const
    {
        PrintMatr(Matr, os);
    }
 
    void PrintSPMatr(std::ostream& os) const
    {
        PrintMatr(MatrSPath, os);
    }
 
    void PrintPMatr(std::ostream& os) const
    {
        PrintMatr(MatrPath, os);
    }
 
    void PrintSt(std::ostream& os)
    {
        while(!Path.empty())
        {
            os<<Path.top()<<' ';
            Path.pop();
        }
        os<<'\n';
    }
private:
    VM MatrPath;
    VM MatrSPath;
    ST Path;
    
    void PrintMatr(const VM& Vec, std::ostream& os) const
    {
        for(size_t i=0; i<Vec.size(); ++i)
        {
            for(size_t j=0; j<Vec.size(); ++j)
            {
                os<<std::setw(3)<<Vec[i][j]<<' ';
            }
            os<<'\n';
        }
    }
 
    void Copy()
    {
        MatrSPath.resize(Matr.size());
        for(size_t i=0; i<Matr.size(); ++i)
            MatrSPath[i].resize(Matr.size());
        for(size_t i=0; i<Matr.size(); ++i)
            std::copy(Matr[i].begin(), Matr[i].end(), MatrSPath[i].begin());
    }
};
 
std::ostream& operator <<(std::ostream& os, const Floyd& Ob)
{
    os<<"Weight matrix\n";
    Ob.PrintWMatr(os);
    os<<"Shortest paths matrix\n";
    Ob.PrintSPMatr(os);
    os<<"Shortest path nodes matrix\n";
    Ob.PrintPMatr(os);
    return os;
}