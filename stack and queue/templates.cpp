template <typename T,typename V>

class Pair
{

T x; 
V y;
public:
T getx()
{
    return x;
}
void setx(T x )
{
  this->x=x;
}
V gety()
{
    return y;
}
void sety(V y )
{
  this->y=y;
}

};