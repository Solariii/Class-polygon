#include <iostream>
#include <string>
#include<cstdlib>
#include<math.h>
#include <string.h>
using namespace std;
bool st[100][100];
class point
{
	float x, y;
public:
	void set_x(float v) { x = v; }
	float get_x() { return x; }
	void set_y(float v) { y = v; }
	float get_y() { return y; }
	double distance(point p) { return sqrt(pow((x - p.x), 2) + pow((y - p.y), 2)); }
	point() { x = y = 0; }
};
class polygon
{
	point p[100];
	int noPoints;
public:
	void set_point(point t) { p[noPoints] = t; noPoints++; }
	point get_point(int i) { return p[i]; }
	void set_NoPoints(int n) { noPoints = n; }
	int get_NoPoints() { return noPoints; }
	polygon() { noPoints = 0; }
	void Total_Redundant_Points(polygon[], int s)
	{
	}
	float get_perimeter()
	{
		float d = 0;
		for (int i = 0; i<noPoints - 1; i++)
		{
			if (i == noPoints - 1)
				d += p[i].distance(p[0]);
			else
				d += p[i].distance(p[i + 1]);
		}
		return d;
	}
	float get_area()
	{
		float area=0;
		for (int i = 0; i<noPoints-1; i++)
		{
			area+=((p[i].get_x()*p[i+1].get_y())-(p[i].get_y()*p[i+1].get_x()));
		}
		area=0.5*(area+((p[noPoints-1].get_x()*p[0].get_y())-(p[noPoints-1].get_y()*p[0].get_x())));
		return area ;
	}
	int List_Triangles(polygon[], int s)
	{
		for (int i = 0; i<s; i++)
		{
		}

	}
};
float Maximum_X(polygon p[], int noPolygons)
{
	float maximum = p[0].get_point(0).get_x();
	for (int j = 0; j <= noPolygons; j++)
	{
		for (int k = 0; k <= p[j].get_NoPoints(); k++)
		{
			if (p[j].get_point(k).get_x()>maximum)
				maximum = p[j].get_point(k).get_x();
		}
	}
	return maximum;
}
float Maximum_Y(polygon p[], int noPolygons)
{
	float maximum = p[0].get_point(0).get_y();
	for (int j = 0; j <= noPolygons; j++)
	{
		for (int k = 0; k <= p[j].get_NoPoints(); k++)
		{
			if (p[j].get_point(k).get_y()>maximum)
				maximum = p[j].get_point(k).get_y();
		}
	}
	return maximum;
}
float Minimum_X(polygon p[], int noPolygons)
{
	float minimum = p[0].get_point(0).get_x();
	for (int j = 0; j <= noPolygons; j++)
	{
		for (int k = 0; k<p[j].get_NoPoints(); k++)
		{
			if (p[j].get_point(k).get_x()<minimum)
				minimum = p[j].get_point(k).get_x();
		}
	}
	return minimum;
}
float Minimum_Y(polygon p[], int noPolygons)
{
	float minimum = p[0].get_point(0).get_y();
	for (int j = 0; j <= noPolygons; j++)
	{
		for (int k = 0; k<p[j].get_NoPoints(); k++)
		{
			if (p[j].get_point(k).get_y()<minimum)
				minimum = p[j].get_point(k).get_y();
		}
	}
	return minimum;
}
int Total_Redundant_Points(polygon p[], int noPolygons)
{
	int count = 0;
	for (int n = 0; n <= noPolygons; n++)
	{
		for (int l = 0; l<p[n].get_NoPoints(); l++)
		{
			if (((p[n].get_point(l + 1).get_y() - p[n].get_point(l).get_y()) / (p[n].get_point(l + 1).get_x() - p[n].get_point(l).get_x())) == ((p[n].get_point(l + 2).get_y() - p[n].get_point(l + 1).get_y()) / (p[n].get_point(l + 2).get_x() - p[n].get_point(l + 1).get_x())))
				count++;
			if ((p[n].get_point(l + 1).get_y() == p[n].get_point(l).get_y()) && (p[n].get_point(l + 1).get_x() == p[n].get_point(l).get_x()))
				count++;
			if (p[n].get_NoPoints() - l == 1)
			{
				if (((p[n].get_point(1).get_y() - p[n].get_point(0).get_y()) / (p[n].get_point(1).get_x() - p[n].get_point(0).get_x())) == ((p[n].get_point(0).get_y() - p[n].get_point(p[n].get_NoPoints()).get_y()) / (p[n].get_point(0).get_x() - p[n].get_point(p[n].get_NoPoints()).get_x())))
					count++;
				if (((p[n].get_point(0).get_y() - p[n].get_point(p[n].get_NoPoints()).get_y()) / (p[n].get_point(0).get_x() - p[n].get_point(p[n].get_NoPoints()).get_x())) == ((p[n].get_point(p[n].get_NoPoints()).get_y() - p[n].get_point(p[n].get_NoPoints() - 1).get_y()) / (p[n].get_point(p[n].get_NoPoints()).get_x() - p[n].get_point(p[n].get_NoPoints() - 1).get_x())))
					count++;
				if ((p[n].get_point(0).get_x() == p[n].get_point(p[n].get_NoPoints()).get_x()) && (p[n].get_point(0).get_y() == p[n].get_point(p[n].get_NoPoints()).get_y()))
					count++;

			}
		}
	}
	return count;
}
int main()
{
	point a[100];
	polygon p[100], po[100],poo[100];
	cout<<"enter string";
	string x =""
		, y = "", z = "",operation ;
	cin>>x;
	int i, j, noPolygons = 0, tempPoints = 0, e = 0;
	float b;
	int v, m;
	float g;
	for (i = 0; i<x.length(); i++)
	{
		if (x[i] == '(')
		{
			g = b = 0;
			y = "";
			for (j = i + 1; j<x.length() && x[j] != ','; j++) y += x[j];

			b = atof(y.c_str());
			a[tempPoints].set_x(b);

			z = "";
			for (m = j + 1; m<x.length() && x[m] != ')'; m++) z += x[m];

			g = atof(z.c_str());
			a[tempPoints].set_y(g);
			p[noPolygons].set_point(a[tempPoints]);
			tempPoints++;
		}
		else if (x[i] == ';')
		{
			tempPoints = 0;
			noPolygons++;
		}
	}
	noPolygons++;
	int f;
	for (int w = 0; w<noPolygons; w++)
	{

		if (((p[w].get_point(0).get_x() == p[w].get_point(p[w].get_NoPoints()-1).get_x()) && (p[w].get_point(0).get_y() == p[w].get_point(p[w].get_NoPoints()-1).get_y())))
		{
			po[w].set_point(p[w].get_point(0));
			st[w][0] = 1;
		}
		else
			f = 0;
		if((((p[w].get_point(1).get_y()-p[w].get_point(0).get_y())/(p[w].get_point(1).get_x()-p[w].get_point(0).get_x()))==((p[w].get_point(0).get_y()-p[w].get_point(p[w].get_NoPoints()-1).get_y())/(p[w].get_point(0).get_x()-p[w].get_point(p[w].get_NoPoints()-1).get_x()))))
				{
					po[w].set_point(p[w].get_point(0));
					st[w][0]=1;
				}
			 if((((p[w].get_point(0).get_y()-p[w].get_point(p[w].get_NoPoints()-1).get_y())/(p[w].get_point(0).get_x()-p[w].get_point(p[w].get_NoPoints()-1).get_x()))==((p[w].get_point(p[w].get_NoPoints()-1).get_y()-p[w].get_point(p[w].get_NoPoints()-2).get_y())/(p[w].get_point(p[w].get_NoPoints()-1).get_x()-p[w].get_point(p[w].get_NoPoints()-2).get_x()))))
			{
				po[w].set_point(p[w].get_point(0));
				st[w][p[w].get_NoPoints()-1]=1;
			}
		for (f=0; f<p[w].get_NoPoints(); f++)
		{

			if ((((p[w].get_point(f + 1).get_y() - p[w].get_point(f).get_y()) / (p[w].get_point(f + 1).get_x() - p[w].get_point(f).get_x())) == ((p[w].get_point(f + 2).get_y() - p[w].get_point(f + 1).get_y()) / (p[w].get_point(f + 2).get_x() - p[w].get_point(f + 1).get_x()))))
			{
				po[w].set_point(p[w].get_point(f));
				st[w][f + 1] = 1;
			}
			if (((p[w].get_point(f + 1).get_y() == p[w].get_point(f).get_y()) && (p[w].get_point(f + 1).get_x() == p[w].get_point(f).get_x())))
			{
				po[w].set_point(p[w].get_point(f));
				st[w][f + 1] = 1;
			}
		}
	}
	for (int gt = 0; gt<noPolygons; gt++)
	{
		for (int vt = 0; vt < p[gt].get_NoPoints(); vt++)
		{
			if (st[gt][vt] == 0)
			{
				poo[gt].set_point(p[gt].get_point(vt));
			}
		}
	}
	cout<<"Enter the operation: ";
	getline(cin,operation);
	int pnn=0;
	if(operation=="Number_Polygons")
		cout<<noPolygons;
	else if (operation=="Total_Number_Points")
	{
		for(int iooo=1;iooo<x.length();iooo++)
	{
		if(x[iooo]==')')
		{
			pnn++;
		}
	}
		cout<<pnn;
	}
	else if (operation=="Minimum_X")
		cout<<Minimum_X(p,noPolygons);
	else if(operation=="Maximum_X")
		cout<<Maximum_X(p,noPolygons);
	else if(operation=="Minimum_Y")
		cout<<Minimum_Y(p,noPolygons);
	else if(operation=="Maximum_Y")
		cout<<Maximum_Y(p,noPolygons);
	else if(operation=="Enclosing_Rectangle")
	{
		cout<<"("<<Minimum_X(p,noPolygons)<<","<<Minimum_Y(p,noPolygons)<<"),"<<"("<<Minimum_X(p,noPolygons)<<","<<Maximum_Y(p,noPolygons)<<"),"<<"("<<Maximum_X(p,noPolygons)<<","<<Maximum_Y(p,noPolygons)<<"),"<<"("<<Maximum_X(p,noPolygons)<<","<<Minimum_Y(p,noPolygons)<<")";
	}
	else if(operation=="Total_Redundant_Points")
		cout<<Total_Redundant_Points(p,noPolygons);
	else if(operation.substr(0,13)=="Polygon_Point")
	{
		int opp=operation.length();
		string hm=operation.substr(14,opp-14);
		int oop;
		oop=atof(hm.c_str());
		for(int kk=0;kk<poo[oop].get_NoPoints();kk++)
		{
			cout<<"("<<poo[oop-1].get_point(kk).get_x()<<","<<poo[oop-1].get_point(kk).get_y()<<"),";
		}
	cout<<endl;
	}
	else if(operation=="Point_Polygons (1,2)")
	{
		bool x = false;
		for(int tem=0; tem<noPolygons ; tem++)
			for(int tee=0 ; tee<p[tem].get_NoPoints();tee++)
				if(p[tem].get_point(tee).get_x()==1 && p[tem].get_point(tee).get_y()==2)
				{
					cout<<++tem<<","; x = true; break;
				}
		if(!x) cout << "This point is not found." << endl;
		else cout << endl;
	}
	else if(operation.substr(0,25)=="List_Polygons_Points More")
	{
		string hmm=operation.substr(26,operation.length()-26);
		int oo=atof(hmm.c_str());
			for(int nnn=0; nnn<noPolygons;nnn++)
			{
				for(int aaa=0 ; aaa<poo[nnn].get_NoPoints();aaa++)
				{
					if(oo<poo[nnn].get_NoPoints())
						cout<<++nnn<<",";
				}
			}
	}
	else if(operation.substr(0,25)=="List_Polygons_Points Less")
	{
		int mmm=operation.length();
				string hmmm=operation.substr(26,mmm-26);
				int oooo=atof(hmmm.c_str());
					for(int nnnn=0; nnnn<noPolygons;nnnn++)
					{
						for(int aaaa=0 ; aaaa<poo[nnnn].get_NoPoints();aaaa++)
						{
							if(oooo>poo[nnnn].get_NoPoints())
								cout<<++nnnn<<",";
						}
					}
	}
	else if(operation.substr(0,26)=="List_Polygons_Points Equal")
	{
		int ll=operation.length();
		string hhh=operation.substr(27,ll-27);
		int oool=atof(hhh.c_str());
			for(int nnnm=0; nnnm<noPolygons;nnnm++)
			{
				for(int ann=0 ; ann<poo[nnnm].get_NoPoints();ann++)
				{
					if(oool==poo[nnnm].get_NoPoints())
						cout<<++nnnm<<",";
				}
			}
	}
	else if(operation.substr(0,25)=="List_Points_Polygons More")
	{
		int sm=operation.length();
		string smh=operation.substr(26,sm-26);
		int coun=atof(smh.c_str()) , counPoints=1;
		bool CheckCoun[100][100];

		for(int ff = 0 ; ff < noPolygons; ff++)
			for(int fs = 0 ; fs < p[ff].get_NoPoints();fs++)
				CheckCoun[ff][fs]=0;

		for(int ff =0; ff<noPolygons; ff++)
		{
			for(int fs=0; fs<p[ff].get_NoPoints(); fs++)
			{

				CheckCoun[ff][fs]=1 , counPoints=1;
				for(int sf = 0 ;  sf < noPolygons; sf++)
				{
					if(ff==sf) continue;
					for(int Ss = 0; CheckCoun[sf][Ss]==0  && Ss<p[sf].get_NoPoints(); Ss++)
					{
						if(p[ff].get_point(fs).get_x() == p[sf].get_point(Ss).get_x() && p[ff].get_point(fs).get_y() == p[sf].get_point(Ss).get_y() )
						{ counPoints++; CheckCoun[sf][Ss]=1; break;}
					}
				}
				if(counPoints>coun)
					cout << "(" << p[ff].get_point(fs).get_x() << "," << p[ff].get_point(fs).get_y() << "),";
			}
		}
	}
	else if(operation.substr(0,25)=="List_Points_Polygons Less")
	{
		int sm=operation.length();
		string smh=operation.substr(26,sm-26);
		int coun=atof(smh.c_str()) , counPoints=1;
		bool CheckCoun[100][100];

		for(int ff = 0 ; ff < noPolygons; ff++)
			for(int fs = 0 ; fs < p[ff].get_NoPoints();fs++)
				CheckCoun[ff][fs]=0;
		int prev= 0;
		for(int ff =0; ff<noPolygons; ff++)
		{
			for(int fs=0; fs<p[ff].get_NoPoints(); fs++)
			{

				if( CheckCoun[ff][fs]==1)
					counPoints=0;
				else CheckCoun[ff][fs]=1 ,counPoints=1;

				for(int sf = 0 ;  sf < noPolygons; sf++)
				{
					if(ff==sf) continue;
					prev = counPoints;
					for(int Ss = 0;  Ss<p[sf].get_NoPoints(); Ss++)
					{
						if( CheckCoun[sf][Ss]==0  && p[ff].get_point(fs).get_x() == p[sf].get_point(Ss).get_x() && p[ff].get_point(fs).get_y() == p[sf].get_point(Ss).get_y() )
						{ 
							if(prev-counPoints == 0)
							{
								counPoints++; CheckCoun[sf][Ss]=1;
							}
							else
								CheckCoun[sf][Ss]=1;
						}
					}
				}
				if(counPoints<coun && counPoints!=0)
					cout << "(" << p[ff].get_point(fs).get_x() << "," << p[ff].get_point(fs).get_y() << "),";
			}
		}
	}
	else if(operation.substr(0,26)=="List_Points_Polygons Equal")
	{
		int sm=operation.length();
		string smh=operation.substr(26,sm-26);
		int coun=atof(smh.c_str()) , counPoints=1;
		bool CheckCoun[100][100];

		for(int ff = 0 ; ff < noPolygons; ff++)
			for(int fs = 0 ; fs < p[ff].get_NoPoints();fs++)
				CheckCoun[ff][fs]=0;
		int prev= 0;
		for(int ff =0; ff<noPolygons; ff++)
		{
			for(int fs=0; fs<p[ff].get_NoPoints(); fs++)
			{

				if( CheckCoun[ff][fs]==1)
					counPoints=0;
				else CheckCoun[ff][fs]=1 ,counPoints=1;

				for(int sf = 0 ;  sf < noPolygons; sf++)
				{
					if(ff==sf) continue;
					prev = counPoints;
					for(int Ss = 0;  Ss<p[sf].get_NoPoints(); Ss++)
					{
						if( CheckCoun[sf][Ss]==0  && p[ff].get_point(fs).get_x() == p[sf].get_point(Ss).get_x() && p[ff].get_point(fs).get_y() == p[sf].get_point(Ss).get_y() )
						{ 
							if(prev-counPoints == 0)
							{
								counPoints++; CheckCoun[sf][Ss]=1;
							}
							else
								CheckCoun[sf][Ss]=1;
						}
					}
				}
				if(counPoints==coun && counPoints!=0)
					cout << "(" << p[ff].get_point(fs).get_x() << "," << p[ff].get_point(fs).get_y() << "),";
			}
		}
	}
	else if(operation.substr(0,17)=="Polygon_Perimeter")
	{
		int pm=operation.length();
		string pmh=operation.substr(18,pm-18);
		int pml=atof(pmh.c_str());
		cout<<poo[pml-1].get_perimeter();
	}
	else if(operation=="List_Triangles")
	{
		for(int kj=0; kj<noPolygons; kj++)
		{
			if(poo[kj].get_NoPoints()==3)
				cout<<++kj<<",";
		}
	}
	else if(operation=="List_Rectangles")
	{
		for(int lg=0; lg<noPolygons;lg++)
		{
			if(poo[lg].get_NoPoints()==4)
			{
				if((poo[lg].get_point(0).distance(poo[lg].get_point(1))==poo[lg].get_point(2).distance(poo[lg].get_point(3)))&&(poo[lg].get_point(0).distance(poo[lg].get_point(2))==poo[lg].get_point(1).distance(poo[lg].get_point(3))))
					cout<<++lg<<",";
			}
		}
	}
	else if(operation=="List_Trapezoid")
	{
		for(int lgg=0; lgg<noPolygons;lgg++)
		{
			if(poo[lgg].get_NoPoints()==4)
			{
				if((((poo[lgg].get_point(1).get_y()-poo[lgg].get_point(0).get_y())/(poo[lgg].get_point(1).get_x()-poo[lgg].get_point(0).get_x()))==((poo[lgg].get_point(2).get_y()-poo[lgg].get_point(3).get_y())/(poo[lgg].get_point(2).get_x()-poo[lgg].get_point(3).get_x())))&&(((poo[lgg].get_point(0).get_y()-poo[lgg].get_point(3).get_y())/(poo[lgg].get_point(0).get_x()-poo[lgg].get_point(3).get_x()))!=((poo[lgg].get_point(1).get_y()-poo[lgg].get_point(2).get_y())/(poo[lgg].get_point(1).get_x()-poo[lgg].get_point(2).get_x()))))
					cout<<++lgg<<",";
			}
		}
	}
	else if(operation.substr(0,12)=="Polygon_Area")
	{
		int am=operation.length();
				string amh=operation.substr(13,am-13);
				int aml=atof(amh.c_str());
				cout<<poo[aml-1].get_area();
	}
	else if(operation=="Inside_Rectangle (1,2),(1,5),(6,5),(6,1)")
	{
		for(int pl=0;pl<noPolygons;pl++)
		{
			for(int lp=0;lp<poo[pl].get_NoPoints();lp++)
			{
				if(((poo[pl].get_point(lp).get_x()>1)&&(poo[pl].get_point(lp).get_x()<6))&&((poo[pl].get_point(lp).get_y()>2)&&(poo[pl].get_point(lp).get_y()<5)))
					cout<<++pl<<",";
			}
		}
	}
	else if(operation=="Inside_Circle (1,2),5")
	{
		for(int pll=0;pll<noPolygons;pll++)
		{
			for(int llp=0;llp<poo[pll].get_NoPoints();llp++)
			{
				if(sqrt(pow((poo[pll].get_point(llp).get_x()-1),2)+pow((poo[pll].get_point(llp).get_y()-2),2))<=5)
					cout<<++pll<<",";
			}
		}
	}
	else if(operation.substr(0,19)=="Polygons_Area_Range")
	{
		int kji=operation.find(",");
		cout<<kji<<endl;
		int kol=++kji;
		cout<<kol<<endl;
		string sth=operation.substr(20,kji-20);
		string hth=operation.substr(kol,operation.length()-kol);
		float minAreaa=atof(sth.c_str());
		float maxAreaa=atof(hth.c_str());
		for(int kii=0;kii<noPolygons;kii++)
		{
			poo[kii].get_area();
			if(poo[kii].get_area()<=maxAreaa&&poo[kii].get_area()>=minAreaa)
			{
				cout<<++kii<<",";
			}
		}
	}
	else if(operation=="quit")
	{
		return 0;
	}
		int dummy;
	cin>>dummy;
	system("pause");
	return 0;
}