#2016/02/04周报

##markdown简单示例

>例子


***



###插入url
[baidu](http://baidu.com)

###插入img
![](http://ww4.sinaimg.cn/bmiddle/aa397b7fjw1dzplsgpdw5j.jpg)

###插入表格
| Tables        | Are           | Cool  |
| ------------- |:-------------:| -----:|
| col 3 is      | right-aligned | $1600 |
| col 2 is      | centered      |   $12 |
| zebra stripes | are neat      |    $1 |

###插入代码
`#include <gdal_priv.h> `

C#:

    //这是一段C#代码
    public class Blog
    {
         public int Id { get; set; }
         public string Subject { get; set; }
    }

Python:

    keywords = ["dsaa","Asd","sadc","Gdfd","gdfdd","gaf","gabdddddd","eg"]
    print dict([(i[0],list(i[1])) for i in groupby(sorted(keywords),lambda    x:x[0].lower())])

Javascript:

    /**
     * nth element in the fibonacci series.
     * @param n >= 0
     * @return the nth element, >= 0.
     */
    function fib(n) {
        var a = 1, b = 1;
        var tmp;
        while (--n >= 0) {
            tmp = a;
            a += b;
           b = tmp;
        }
        return a;
    }

    document.write(fib(10));

###粗体斜体
**刘月**
*六岳*

###插入latex公式
![](http://latex.codecogs.com/gif.latex?\prod%20\(n_{i}\)+1)


