## 1180诡异的楼梯

```c++
	while (!q.empty()){
		temp = q.top(), q.pop();
		if (ex == temp.x&&ey == temp.y)return temp.t;//return---1
		for (int i = 0; i < 4; ++i){
			x = temp.x + dir[i][0];
			y = temp.y + dir[i][1];
			if (x < 0 || y < 0 || x >= m || y >= n)continue;
			if (a[x][y] == -1)continue;
			if (a[x][y] == 0 || a[x][y] == 1){
				int xx = x + dir[i][0], yy = y + dir[i][1];
				if (xx < 0 || yy < 0 || xx >= m || yy >= n)continue;
				node.x = xx, node.y = yy;
				if (getDir(x, y, temp.t, i)) node.t = temp.t + 2;
				else node.t = temp.t + 1;
                //if (ex == node.x&&ey == node.y)return node.t;    return---2
				q.push(node);	
			}
			else{
				a[x][y] = -1;///////////only this pos
				node.x = x, node.y = y, node.t = temp.t+1;
                //if (ex == node.x&&ey == node.y)return node.t;    return---2
				q.push(node);
			}

		}
	}
```



- 关于return放哪里的问题

我们不讨论代码的简洁性，如果放在return---2的两个部分会出什么问题？可以看到return---2是在下一步走了以后立即判断是不是能达到，但是可能出现的一种情况是：等楼梯等了一分钟再走的，也就是本来可以最少花一分钟现在花了两分钟，这样有可能在别的情况下被超过，所以这样的判断会出问题。

那么平时为什么可以放在里面判断呢？因为一般情况下都是每次只能走一步，不会存在被超过的情况。

- 关于标记被访问过

一种是用vis[]，一种是利用题目中设置的不可到达点，将访问过的位置标记为其值即可。

注意：我们看到只有注释的部分修改了不可到达的值，因为上面会有一种情况是现在过楼梯时花了两分钟到达了，但是之后可能被超越——那如果被修改了的话，就不能更新，也就是说与楼梯连的地方要谨慎。