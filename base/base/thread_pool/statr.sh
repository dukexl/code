SOURCE="${BASH_SOURCE[0]}"
#message(${SOURCE})
echo ${SOURCE} #./start.sh
SOURCE_DIR=`dirname $SOURCE`  #dirname命令可以取给定路径的目录部分
echo ${SOURCE_DIR} # .

# 跳转到脚本所在目录  
cd $(dirname "$0") || exit 1  

QUICKFAST_ROOT=`readlink -f $SOURCE_DIR` # readlink是Linux系统中一个常用工具，主要用来找出符号链接所指向的位置
echo ${QUICKFAST_ROOT} # /home/xuli/code/learn/test/code 当前shell脚本所在的位置

export QUICKFAST_ROOT=`readlink -f $SOURCE_DIR` # export到处环境变量

# 判断BOOST_ROOT是否存在，不存在导出
#if test "$BOOST_ROOT"=""
#then
#    export BOOST_ROOT=/usr/local/include/boost
#fi
pidCmd='ps aux|fgrep jiaoyisuo_vss|fgrep -v fgrep|awk "{print \$2 }"'
echo ${pidCmd}
PID=`eval $pidCmd`
echo ${PID}