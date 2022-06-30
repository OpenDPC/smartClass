const koa = require("koa");
const static = require("koa-static");
const Router = require("koa-router");
const koabody = require("koa-body");
const fs = require("fs");
const cors = require("koa-cors");
let app = new koa();
let router = new Router();
app.use(static(__dirname+"/static"));
app.use(koabody({
    multipart:true
}));

router.post("/upload",(ctx,next)=>{
    // console.log(ctx.request.body);
    //  console.log(ctx.request.files.obj);
    //  console.log("======");
    //  console.log(ctx.request.files.obj.filepath);
    //  console.log(ctx.request.files.obj.originalFilename);


     let filedata = fs.readFileSync(ctx.request.files.obj.filepath);
     fs.writeFileSync("static/files/"+ctx.request.files.obj.originalFilename,filedata);

    ctx.body = "请求成功";
})






app.use(router.routes());
app.use(router.allowedMethods());
app.listen(3000);
