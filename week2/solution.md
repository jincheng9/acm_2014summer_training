1 POj 1365 - Prime Land

对一个数进行素数分解，思路是从最小的素数2开始逐个进行素数分解

麻烦的地方在于数据的读取，可以用getline读取整行，然后用strtok进行分解得到我们要的数

tip: 我之前用memset对int数组进行初始化犯了一个错误，那就是memset的第三个参数是字节数，而不是整数个数。

如果要把size=1000的int数组a全部初始化为0，应该是memset(a, 0, 4000)，而不是memset(a, 0, 1000)。

2 POJ 1006 - Biorhythms

p+23x = e + 28y = i+33z，因为23, 28, 33两两互素，可以用中国剩余定理求解。

这道题由于数据规模比较小，暴力枚举也可以AC.

3 POJ 2689 - Prime Distance

快速筛素数，可以先求出2到sqrt(2147483647)之间的所有素数，然后用这些素数去筛选L和U之间的素数，再对筛到的素数扫描一遍即可。

4 POJ 2417 - Discrete Logging

离散对数，可以用baby step giant step算法求解。

思路是把L表示成i*m+j的形式，m= ceil(sqrt(P))，0<=i, j<m,  B^(i*m+j) = N(modP) => B^j = N*inv(B^(im))(modP)

先遍历j=0,1,...,m-1，求出所有的B^j(modP)，存到数组array中，然后遍历i，如果N*inv(B^(im))(modP)的值能够在array中搜到，
即表示找到了L。需要对array进行排序，以用来进行二分查找。
