var md5 = require('./md5.js');
const url = require('url');
// 1. 导入http模块
var http = require('http');
// 2. 使用http这个模块中的createServer()创建一个服务器实例对象
var server = http.createServer();
// 3. 绑定端口号,启动web服务器
server.listen(8080, function() {
    console.log(' Server running at http://localhost:8080');
});
// 4. 为这个服务器实例对象注册 request 请求处理函数
// 请求处理函数function(形参1,形参2){}
// 形参1:request请求对象 获取到当前请求的路径,方法等本次请求的所有信息
// 形参2:response响应对象 发送响应数据
server.on('request', function(request, response) {
	md5().then((instance) => {
		response.writeHead(200,{"content-type":"text/html;charset=utf-8"});
		var url = request.url;
		if(url.indexOf('?')>0){
			var count = url.split('?')[1];
			var time = instance._md5(count);
			response.write('Run '+count + ' times cost: ' + time + ' ms ');
		}
		response.end();
	}); 
});