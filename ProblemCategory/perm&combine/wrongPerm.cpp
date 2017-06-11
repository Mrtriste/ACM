//http://blog.csdn.net/worker90/article/details/6624977

long long wrong[40];

void init(){
	wrong[0] = 1, wrong[1] = 0;
	wrong[2] = 1, wrong[3] = 2;
	for (int i = 3; i <= 14; ++i)
		wrong[i] = (wrong[i - 1] + wrong[i - 2])*(i - 1);
}