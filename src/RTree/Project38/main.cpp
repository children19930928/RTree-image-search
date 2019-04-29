
#include "LoadImage.h"
#include "RTree.h"
int TEST_TIME = 5000;
int NODE_NUMBER = 1000;
#define INT_RANGE 65536
using namespace std;
void TestRtreeTest();
void TestRtreeSingalNode(int& totalHits,int k,int option);//option就是维度
void SearchImage(int& num1, int& num3,int option,char searchName[]);
void searchImageTest();
void quertListTest();
void queryByList(int& num1,int& num3,int option,int times);
void randomInt(int n,int a[])//n为要生成的随机数个数,a为储存的数组
{
	for(int i = 0; i < n;i++)
	{
		a[i] = (rand() * rand()) % INT_RANGE;
		//cout << a[i] << ' ';
	}
	//cout << endl;
}

struct Rect
{
	int* min;
	int* max;
	void remove()
	{
		delete []min;
		delete []max;
	}
	Rect(int n,int* a_min,int* a_max)
	{
		min = new int[n];
		max = new int[n];
		for(int i = 0; i < n; i++)
		{
			min[i] = a_min[i];
			max[i] = a_max[i];
		}
	}

};

bool MySearchCallback(int id, void* arg) 
{
  return true; // keep going
}

void searchImageTest()
{
	cout << "选择测试的特征:1为RGB直方图,2为HSV，3为灰度共生矩阵(8),4为HSV(16),5为RGB(16)" << endl;
	int num1;
	int num2;
	int option;
	char searchName[] = {"n07897438_43.JPEG"};//要查找图片的名字
	cout << searchName <<"是示例图片" << endl;
	cin >> option ;
	cout << "输入你想要查询的文件名" <<endl;
	cin >> searchName;
	SearchImage(num1,num2,option,searchName);
}


void TestRtreeSingalNode(int& totalHits,int k,int option)//option就是维度
 {
	int nhits;
	int* min = new int[DIMMAX+1];
	int* max = new int[DIMMAX+1];
	int num = 0;
	if(option == 4)
	{
	RTree<int, int, 4,float> tree;
	num = 4;
	totalHits = 0;
		for(int i = 0; i < NODE_NUMBER ; i ++ )
		{
			randomInt(num,min);
			for(int j = 0; j < num ; j++)
			{
				max[j] = min[j];
			}
			tree.Insert(min, max, i,"0"); // Note, all values including zero are fine in this version
		}
	//进行TEST_TIME次的查询
	for(int w = 0; w < TEST_TIME;w++)
		{
		randomInt(num,min);
		for(int i = 0; i < num; i ++ )
		{
			max[i] =  min[i];
		}
		 Rect search(num,min,max);
		 nhits = tree.kNNSearch(k,search.min,num);
		 totalHits +=  nhits;
		 search.remove();
		}
	delete []min;
	delete []max;
	}
	else if(option == 8)
	{
			RTree<int, int, 8,float> tree;
			num = 8;
			totalHits = 0;
		for(int i = 0; i < NODE_NUMBER ; i ++ )
		{
			randomInt(num,min);
			for(int j = 0; j < num ; j++)
			{
				max[j] = min[j];
			}
			tree.Insert(min, max, i,"0"); // Note, all values including zero are fine in this version
		}
	//进行TEST_TIME次的查询
	for(int w = 0; w < TEST_TIME;w++)
		{
		randomInt(num,min);
		for(int i = 0; i < num; i ++ )
		{
			max[i] =  min[i];
		}
		 Rect search(num,min,max);
		  nhits = tree.kNNSearch(k,search.min,num);
		 totalHits +=  nhits;
		 search.remove();
		}
	delete []min;
	delete []max;
	}
	else if(option == 12)
	{
		RTree<int, int, 12,float> tree;
		num = 12;
		totalHits = 0;
		for(int i = 0; i < NODE_NUMBER ; i ++ )
		{
			randomInt(num,min);
			for(int j = 0; j < num ; j++)
			{
				max[j] = min[j];
			}
			tree.Insert(min, max, i,"0"); // Note, all values including zero are fine in this version
		}
	//进行TEST_TIME次的查询
	for(int w = 0; w < TEST_TIME;w++)
		{
		randomInt(num,min);
		for(int i = 0; i < num; i ++ )
		{
			max[i] =  min[i];
		}
		 Rect search(num,min,max);
		 nhits = tree.kNNSearch(k,search.min,num);
		 totalHits +=  nhits;
		 search.remove();
		}
	delete []min;
	delete []max;
	}
	else if(option == 16)
	{
		RTree<int, int, 16,float> tree;
		num = 16;
		totalHits = 0;
		for(int i = 0; i < NODE_NUMBER ; i ++ )
		{
			randomInt(num,min);
			for(int j = 0; j < num ; j++)
			{
				max[j] = min[j];
			}
			tree.Insert(min, max, i,"0"); // Note, all values including zero are fine in this version
		}
	//进行TEST_TIME次的查询
	for(int w = 0; w < TEST_TIME;w++)
		{
		randomInt(num,min);
		for(int i = 0; i < num; i ++ )
		{
			max[i] =  min[i];
		}
		 Rect search(num,min,max);
		  nhits = tree.kNNSearch(k,search.min,num);
		 totalHits +=  nhits;
		 search.remove();
		}
	delete []min;
	delete []max;
	}
	else if(option == 20)
	{
		RTree<int, int, 20,float> tree;
		num = 20;
		totalHits = 0;
		for(int i = 0; i < NODE_NUMBER ; i ++ )
		{
			randomInt(num,min);
			for(int j = 0; j < num ; j++)
			{
				max[j] = min[j];
			}
			tree.Insert(min, max, i,"0"); // Note, all values including zero are fine in this version
		}
	//进行TEST_TIME次的查询
	for(int w = 0; w < TEST_TIME;w++)
		{
		randomInt(num,min);
		for(int i = 0; i < num; i ++ )
		{
			max[i] =  min[i];
		}
		 Rect search(num,min,max);
		  nhits = tree.kNNSearch(k,search.min,num);
		 totalHits +=  nhits;
		 search.remove();
		}
	delete []min;
	delete []max;
	}
	else if(option == 64)
	{
		RTree<int, int, 64,float> tree;
		num = 64;
		totalHits = 0;
		for(int i = 0; i < NODE_NUMBER ; i ++ )
		{
			randomInt(num,min);
			for(int j = 0; j < num ; j++)
			{
				max[j] = min[j];
			}
			tree.Insert(min, max, i,"0"); // Note, all values including zero are fine in this version
		}
	//进行TEST_TIME次的查询
	for(int w = 0; w < TEST_TIME;w++)
		{
		randomInt(num,min);
		for(int i = 0; i < num; i ++ )
		{
			max[i] =  min[i];
		}
		 Rect search(num,min,max);
		  nhits = tree.kNNSearch(k,search.min,num);
		 totalHits +=  nhits;
		 search.remove();
		}
	delete []min;
	delete []max;
	}
 }

void SearchImage(int& num1, int& num3,int option,char searchName[])//查找指定图片的准确,找到的结果和正确的个数
{
	if(option == 1)
	{
		num1 = 0;
		num3 = 0;
		int k = 0;
		int num = 8;
		cout << "输入你想查找的图片数?" <<endl;
		cin >> k;
		int searchNodes = 0;
		vector< m_image<int> > res;
		int totalHits = 0;
		int nhits;
		int* min = new int[DIMMAX+1];
		int* max = new int[DIMMAX+1];
		RTree<int, int, 8,float> tree;
		int re[DIMMAX+10];
		
			getImageOwnFeature("data_color_RGB_08(2.2.2).txt",res,num);
			//getImageOwnFeature("data_color_HSV.txt",res);
			//getImageOwnFeature("data_tex.txt",res);
		for(int i = 0; i < res.size() ; i ++ )
			{
			
			tree.Insert(res[i].m_rectangle.m_min, res[i].m_rectangle.m_max, res[i].m_imageID,res[i].m_imageName); // Note, all values including zero are fine in this version
			}
			RGB_Color_Histogram(searchName,re);
		
		for(int i = 0; i < num; i ++ )
		{
			min[i] = re[i];
			max[i] =  min[i];
		}
		cout << searchName << endl;
		Rect search(num,min,max);
		nhits = tree.kNNSearch(k,search.min,num);
		//nhits = tree.Search(search.min,search.max,MySearchCallback, NULL);
		totalHits +=  nhits;
		cout << (float)totalHits  << endl;
		int wy = 0;
		wy = tree.TestRightTimes(k,searchName);
		num1+= wy;
		num3 += k;
		search.remove();
		tree.kNNdelete();
		cout << "正确个数是" << num1 << endl;
		cout << num3 << endl;
		delete []min;
		delete []max;
		   getchar();
		   getchar();
	}
	else if(option == 2)
	{		num1 = 0;
		num3 = 0;
		int k = 0;
		int num = 20;
		cout << "输入你想查找的图片数?" <<endl;
		cin >> k;
		int searchNodes = 0;
		vector< m_image<int> > res;
		int totalHits = 0;
		int nhits;
		int* min = new int[DIMMAX+1];
		int* max = new int[DIMMAX+1];
		RTree<int, int, 20,float> tree;
		int re[DIMMAX+10];
		
			//getImageOwnFeature("data_color_RGB.txt",res,num);
			getImageOwnFeature("data_color_HSV_20(5.2.2).txt",res,num);
			//getImageOwnFeature("data_tex.txt",res);
		for(int i = 0; i < res.size() ; i ++ )
			{
			
			tree.Insert(res[i].m_rectangle.m_min, res[i].m_rectangle.m_max, res[i].m_imageID,res[i].m_imageName); // Note, all values including zero are fine in this version
			}
			HSV_Color_Histogram(searchName,re);
		
		for(int i = 0; i < num; i ++ )
		{
			min[i] = re[i];
			max[i] =  min[i];
		}
		cout << searchName << endl;
		Rect search(num,min,max);
		nhits = tree.kNNSearch(k,search.min,num);
		//nhits = tree.Search(search.min,search.max,MySearchCallback, NULL);
		totalHits +=  nhits;
		cout << (float)totalHits  << endl;
		int wy = 0;
		wy = tree.TestRightTimes(k,searchName);
		num1+= wy;
		num3 += k;
		search.remove();
		tree.kNNdelete();
		cout << "正确个数是" << num1 << endl;
		cout << num3 << endl;
		delete []min;
		delete []max;
		   getchar();
		   getchar();
	}
	else if(option == 3)
	{		num1 = 0;
		num3 = 0;
		int k = 0;
		int num = 20;
		cout << "输入你想查找的图片数?" <<endl;
		cin >> k;
		int searchNodes = 0;
		vector< m_image<int> > res;
		int totalHits = 0;
		int nhits;
		int* min = new int[DIMMAX+1];
		int* max = new int[DIMMAX+1];
		RTree<int, int, 20,float> tree;
		int re[DIMMAX+10];
		
			//getImageOwnFeature("data_color_RGB.txt",res,num);
			//getImageOwnFeature("data_color_HSV.txt",res);
			getImageOwnFeature("data_tex.txt",res,20);
		for(int i = 0; i < res.size() ; i ++ )
			{
			
			tree.Insert(res[i].m_rectangle.m_min, res[i].m_rectangle.m_max, res[i].m_imageID,res[i].m_imageName); // Note, all values including zero are fine in this version
			}
			GrayLevel_Cooccurrence_Matrix(searchName,re);
		
		for(int i = 0; i < num; i ++ )
		{
			min[i] = re[i];
			max[i] =  min[i];
		}
		cout << searchName << endl;
		Rect search(num,min,max);
		nhits = tree.kNNSearch(k,search.min,num);
		//nhits = tree.Search(search.min,search.max,MySearchCallback, NULL);
		totalHits +=  nhits;
		cout << (float)totalHits  << endl;
		int wy = 0;
		wy = tree.TestRightTimes(k,searchName);
		num1+= wy;
		num3 += k;
		search.remove();
		tree.kNNdelete();
		cout << "正确个数是" << num1 << endl;
		cout << num3 << endl;
		delete []min;
		delete []max;
		   getchar();
		   getchar();
	}
	else if(option == 4)
		{		num1 = 0;
		num3 = 0;
		int k = 0;
		int num = 16;
		cout << "输入你想查找的图片数?" <<endl;
		cin >> k;
		int searchNodes = 0;
		vector< m_image<int> > res;
		int totalHits = 0;
		int nhits;
		int* min = new int[DIMMAX+1];
		int* max = new int[DIMMAX+1];
		RTree<int, int, 16,float> tree;
		int re[DIMMAX+10];
		
			//getImageOwnFeature("data_color_RGB.txt",res,num);
			getImageOwnFeature("data_color_HSV_4.2.2.txt",res,16);
			//getImageOwnFeature("data_tex.txt",res);
		for(int i = 0; i < res.size() ; i ++ )
			{
			
			tree.Insert(res[i].m_rectangle.m_min, res[i].m_rectangle.m_max, res[i].m_imageID,res[i].m_imageName); // Note, all values including zero are fine in this version
			}
			HSV_Color_Histogram(searchName,re);
		
		for(int i = 0; i < num; i ++ )
		{
			min[i] = re[i];
			max[i] =  min[i];
		}
		cout << searchName << endl;
		Rect search(num,min,max);
		nhits = tree.kNNSearch(k,search.min,num);
		//nhits = tree.Search(search.min,search.max,MySearchCallback, NULL);
		totalHits +=  nhits;
		cout << (float)totalHits  << endl;
		int wy = 0;
		wy = tree.TestRightTimes(k,searchName);
		num1+= wy;
		num3 += k;
		search.remove();
		tree.kNNdelete();
		cout << "正确个数是" << num1 << endl;
		cout << num3 << endl;
		delete []min;
		delete []max;
		   getchar();
		   getchar();
	}
		else if(option == 5)
		{		
			num1 = 0;
		num3 = 0;
		int k = 0;
		int num = 16;
		cout << "输入你想查找的图片数?" <<endl;
		cin >> k;
		int searchNodes = 0;
		vector< m_image<int> > res;
		int totalHits = 0;
		int nhits;
		int* min = new int[DIMMAX+1];
		int* max = new int[DIMMAX+1];
		RTree<int, int, 16,float> tree;
		int re[DIMMAX+10];
		
			//getImageOwnFeature("data_color_RGB.txt",res,num);
			getImageOwnFeature("data_color_RGB_2.4.2.txt",res,num);
			//getImageOwnFeature("data_tex.txt",res);
		for(int i = 0; i < res.size() ; i ++ )
			{
			
			tree.Insert(res[i].m_rectangle.m_min, res[i].m_rectangle.m_max, res[i].m_imageID,res[i].m_imageName); // Note, all values including zero are fine in this version
			}
			//HSV_Color_Histogram(searchName,re);
		
		for(int i = 0; i < num; i ++ )
		{
			min[i] = re[i];
			max[i] =  min[i];
		}
		cout << searchName << endl;
		Rect search(num,min,max);
		nhits = tree.kNNSearch(k,search.min,num);
		//nhits = tree.Search(search.min,search.max,MySearchCallback, NULL);
		totalHits +=  nhits;
		cout << (float)totalHits  << endl;
		int wy = 0;
		wy = tree.TestRightTimes(k,searchName);
		num1+= wy;
		num3 += k;
		search.remove();
		tree.kNNdelete();
		cout << "正确个数是" << num1 << endl;
		cout << num3 << endl;
		delete []min;
		delete []max;
		   getchar();
		   getchar();
	}
}
void TestRtreeTest()
{
	srand((unsigned)time(NULL));
	int totalHits = 0;
	int k = 0;
	int option;
	cout << "测试输入维数,能支持4、8、12、16、64" <<endl; 
	cin >> option;
	cout << "请输入近邻的个数" <<endl;
	cin >> k;
	TEST_TIME = 500;
		for(NODE_NUMBER = 1000; NODE_NUMBER < 6000;NODE_NUMBER +=1000)
	{
		totalHits = 0;
		TestRtreeSingalNode(totalHits,k,option);
		cout << NODE_NUMBER << "个节点查询" <<k << "近邻"<< endl;
		cout << (float)totalHits / (float)TEST_TIME << "个平均访问节点" << endl;
	}
}

void queryListTest()
{
	cout << "选择测试的特征:1为RGB直方图2*2*2,2为测试已给的9维特征，3为灰度共生矩阵(8),4为HSV(8),5为RGB(16)" << endl;
	int num1;
	int num3;
	int option;
	cin >> option;
	//for(int i = 1000; i < 6000;i+=1000)
	//{
		queryByList(num1,num3,option,5000);
	//}
}
void queryByList(int& num1,int& num3,int option,int times)//通过读入的特征文本来查找类似的，可用于测试准确度，times为查询的次数
{
	if(option == 1)
	{
		num1 = 0;
		num3 = 0;
		int k = 0;
		int num = 8;
		TEST_TIME = times;
		char searchName[255];
		cout << "输入你想查找的图片数?" <<endl;
		cin >> k;
		int searchNodes = 0;
		vector< m_image<int> > res;
		int totalHits = 0;
		srand((unsigned)time(NULL));
		int nhits;
		int* min = new int[DIMMAX+1];
		int* max = new int[DIMMAX+1];
		RTree<int, int, 8,float> tree;
		int re[DIMMAX+10];
		getImageOwnFeature("data_color_RGB_08(2.2.2).txt",res,num);
	
		for(int i = 0; i < res.size() ; i ++ )
		{
		
		tree.Insert(res[i].m_rectangle.m_min, res[i].m_rectangle.m_max, res[i].m_imageID,res[i].m_imageName); // Note, all values including zero are fine in this version
		}
		for(int j = 0; j < TEST_TIME;j++)
		{
		//infile >> searchName;
			for(int i = 0; i < num; i ++ )
			{
				//min[i] = *res[i].m_rectangle.m_min;
				min[i] = res[j].m_rectangle.m_min[i];
				max[i] =  min[i];
				//cout << min[i] << ' ';
			}
			for(int i = 0; i < 30;i++)
			searchName[i] = res[j].m_imageName[i];
			//cout << searchName << endl;
			Rect search(num,min,max);
			nhits = tree.kNNSearch(k,search.min,num);
			//nhits = tree.Search(search.min,search.max,MySearchCallback, NULL);
			totalHits +=  nhits;
			int wy = 0;
			wy = tree.TestRightTimes(k,searchName);
			num1 += wy;
			num3 += k;
			search.remove();
			tree.kNNdelete();
		}
		cout << "平均查找次数是"<<(float)totalHits /(float)TEST_TIME << endl;
		cout << "正确个数是" << num1 << endl;
		cout << "总的查找个数是" <<num3 << endl;
			delete []min;
		delete []max;
		   getchar();
		   getchar();
	}
	else if(option == 2)
	{
		num1 = 0;
		num3 = 0;
		int k = 0;
		int num = 9;
		TEST_TIME = times;
		char searchName[255];
		//cout << "输入你想查找的图片数?" <<endl;
		//cin >> k;
		k = 40;
		int searchNodes = 0;
		vector< m_image<int> > res;
		int totalHits = 0;
		srand((unsigned)time(NULL));
		int nhits;
		int* min = new int[DIMMAX+1];
		int* max = new int[DIMMAX+1];
		RTree<int, int, 9,float> tree;
		int re[DIMMAX+10];
		//getImageOwnFeature("data_color_HSV_08(2.2.2)",res,num);
		getImageFeatureGiven("imagelist.txt","color_feature.txt",res,num);
		for(int i = 0; i < res.size() ; i ++ )
		{
		
		tree.Insert(res[i].m_rectangle.m_min, res[i].m_rectangle.m_max, res[i].m_imageID,res[i].m_imageName); // Note, all values including zero are fine in this version
		}
		for(int j = 0; j < TEST_TIME;j++)
		{
		//infile >> searchName;
			for(int i = 0; i < num; i ++ )
			{
				//min[i] = *res[i].m_rectangle.m_min;
				min[i] = res[j].m_rectangle.m_min[i];
				max[i] =  min[i];
				//cout << min[i] << ' ';
			}
			for(int i = 0; i < 30;i++)
			searchName[i] = res[j].m_imageName[i];
			//cout << searchName << endl;
			Rect search(num,min,max);
			nhits = tree.kNNSearch(k,search.min,num);
			//nhits = tree.Search(search.min,search.max,MySearchCallback, NULL);
			totalHits +=  nhits;
			int wy = 0;
			wy = tree.TestRightTimes(k,searchName);
			num1 += wy;
			num3 += k;
			search.remove();
			tree.kNNdelete();
		}
		cout << TEST_TIME << "次查询"<<endl;
		cout << "平均查找次数是"<<(float)totalHits /(float)TEST_TIME << endl;
		//cout << "正确个数是" << num1 << endl;
		//cout <<"总的查找个数是" <<num3 << endl;
		cout << "正确率是" << (float)num1 / (float)num3 << endl;
		delete []min;
		delete []max;
		  // getchar();
		   //getchar();
	}
	else if(option == 3)
	{
		num1 = 0;
		num3 = 0;
		int k = 0;
		int num = 20;
		TEST_TIME = times;
		char searchName[255];
		cout << "输入你想查找的图片数?" <<endl;
		cin >> k;
		int searchNodes = 0;
		vector< m_image<int> > res;
		int totalHits = 0;
		srand((unsigned)time(NULL));
		int nhits;
		int* min = new int[DIMMAX+1];
		int* max = new int[DIMMAX+1];
		RTree<int, int, 20,float> tree;
		int re[DIMMAX+10];
		getImageOwnFeature("data_color_HSV.txt",res,num);
	
		for(int i = 0; i < res.size() ; i ++ )
		{
		
		tree.Insert(res[i].m_rectangle.m_min, res[i].m_rectangle.m_max, res[i].m_imageID,res[i].m_imageName); // Note, all values including zero are fine in this version
		}
		for(int j = 0; j < TEST_TIME;j++)
		{
		//infile >> searchName;
			for(int i = 0; i < num; i ++ )
			{
				//min[i] = *res[i].m_rectangle.m_min;
				min[i] = res[j].m_rectangle.m_min[i];
				max[i] =  min[i];
				//cout << min[i] << ' ';
			}
			for(int i = 0; i < 30;i++)
			searchName[i] = res[j].m_imageName[i];
			//cout << searchName << endl;
			Rect search(num,min,max);
			nhits = tree.kNNSearch(k,search.min,num);
			//nhits = tree.Search(search.min,search.max,MySearchCallback, NULL);
			totalHits +=  nhits;
			int wy = 0;
			wy = tree.TestRightTimes(k,searchName);
			num1 += wy;
			num3 += k;
			search.remove();
			tree.kNNdelete();
		}
		cout << "平均查找次数是"<<(float)totalHits /(float)TEST_TIME << endl;
		cout << "正确个数是" << num1 << endl;
		cout << "总的查找个数是" <<num3 << endl;
			delete []min;
		delete []max;
		   getchar();
		   getchar();
	}
	else if(option == 4)
	{
		num1 = 0;
		num3 = 0;
		int k = 0;
		int num = 8;
		TEST_TIME = times;
		char searchName[255];
		cout << "输入你想查找的图片数?" <<endl;
		cin >> k;
		int searchNodes = 0;
		vector< m_image<int> > res;
		int totalHits = 0;
		srand((unsigned)time(NULL));
		int nhits;
		int* min = new int[DIMMAX+1];
		int* max = new int[DIMMAX+1];
		RTree<int, int, 8,float> tree;
		int re[DIMMAX+10];
		getImageOwnFeature("data_color_HSV_08(2.2.2).txt",res,num);
	
		for(int i = 0; i < res.size() ; i ++ )
		{
		
		tree.Insert(res[i].m_rectangle.m_min, res[i].m_rectangle.m_max, res[i].m_imageID,res[i].m_imageName); // Note, all values including zero are fine in this version
		}
		for(int j = 0; j < TEST_TIME;j++)
		{
		//infile >> searchName;
			for(int i = 0; i < num; i ++ )
			{
				//min[i] = *res[i].m_rectangle.m_min;
				min[i] = res[j].m_rectangle.m_min[i];
				max[i] =  min[i];
				//cout << min[i] << ' ';
			}
			for(int i = 0; i < 30;i++)
			searchName[i] = res[j].m_imageName[i];
			//cout << searchName << endl;
			Rect search(num,min,max);
			nhits = tree.kNNSearch(k,search.min,num);
			//nhits = tree.Search(search.min,search.max,MySearchCallback, NULL);
			totalHits +=  nhits;
			int wy = 0;
			wy = tree.TestRightTimes(k,searchName);
			num1 += wy;
			num3 += k;
			search.remove();
			tree.kNNdelete();
		}
		cout <<"平均查找次数是"<< (float)totalHits /(float)TEST_TIME << endl;
		cout << "正确个数是" << num1 << endl;
		cout << "总的查找个数是" <<num3 << endl;
			delete []min;
			delete []max;
		   getchar();
		   getchar();
	}
		else if(option == 5)
	{
		num1 = 0;
		num3 = 0;
		int k = 0;
		int num = 16;
		TEST_TIME = times;
		char searchName[255];
		cout << "输入你想查找的图片数?" <<endl;
		cin >> k;
		int searchNodes = 0;
		vector< m_image<int> > res;
		int totalHits = 0;
		srand((unsigned)time(NULL));
		int nhits;
		int* min = new int[DIMMAX+1];
		int* max = new int[DIMMAX+1];
		RTree<int, int, 16,float> tree;
		int re[DIMMAX+10];
		getImageOwnFeature("data_color_RGB_2.4.2.txt",res,num);
	
		for(int i = 0; i < res.size() ; i ++ )
		{
		
		tree.Insert(res[i].m_rectangle.m_min, res[i].m_rectangle.m_max, res[i].m_imageID,res[i].m_imageName); // Note, all values including zero are fine in this version
		}
		for(int j = 0; j < TEST_TIME;j++)
		{
		//infile >> searchName;
			for(int i = 0; i < num; i ++ )
			{
				//min[i] = *res[i].m_rectangle.m_min;
				min[i] = res[j].m_rectangle.m_min[i];
				max[i] =  min[i];
				//cout << min[i] << ' ';
			}
			for(int i = 0; i < 30;i++)
			searchName[i] = res[j].m_imageName[i];
			//cout << searchName << endl;
			Rect search(num,min,max);
			nhits = tree.kNNSearch(k,search.min,num);
			//nhits = tree.Search(search.min,search.max,MySearchCallback, NULL);
			totalHits +=  nhits;
			int wy = 0;
			wy = tree.TestRightTimes(k,searchName);
			num1 += wy;
			num3 += k;
			search.remove();
			tree.kNNdelete();
		}
		cout << "平均查找次数是"<< (float)totalHits /(float)TEST_TIME << endl;
		cout << "正确个数是" << num1 << endl;
		cout << "总的查找个数是" <<num3 << endl;
			delete []min;
			delete []max;
		   getchar();
		   getchar();
	}
}


int main()
{
	cout << "当前的结点上限是256，下限是128，可以在RTree.h中修改" <<endl;
	int num1;
	int num3;
	int option;
	cout << "1为测试r树,2为查找单个图片,3为图片准确率查询" << endl;
	cin >> option;
	//cout << "选择测试的特征:1为RGB直方图,2为HSV(20)，3为灰度共生矩阵,4为HSV(16),5为TGB(16)" << endl;
	//cin >> option;	
	switch(option)
	{
	case 1:
		TestRtreeTest();
		break;
	case 2:
		searchImageTest();
		break;
	case 3:
		queryListTest();
			break;
	}
	getchar();
	getchar();
	return 0;
}