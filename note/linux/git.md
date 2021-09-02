第一 git note
1 git add xxx
2 git commit -m "xxx"
3 git push
4 git config --global credential.helper store
5 vscode add

远程仓库
1，git remote add origin 远程仓库地址
2，git pull origin master --allow-unrelated-histories
3，git branch --set-upstream-to=origin/master master
4，git push


第三 linux系统的一些问题
echo 'source /opt/centos/devtoolset-1.1/enable' >> ~/.bash_profile 
source ~/.bash_profile 每次重新电脑后gcc会变成低版本的gcc


第四 C++ 基础问题
1）enable_shared_from_this 用来保活
若一个类 T 继承 std::enable_shared_from_this<T> ，则会为该类 T 提供成员函数： shared_from_this 。 
当 T 类型对象 t 被一个为名为 pt 的 std::shared_ptr<T> 类对象管理时，调用 T::shared_from_this 成员函数，
将会返回一个新的 std::shared_ptr<T> 对象，它与 pt 共享 t 的所有权
