!function(e,o,t){var a,i=[];e.requestAnimationFrame=e.requestAnimationFrame||e.webkitRequestAnimationFrame||e.mozRequestAnimationFrame||e.oRequestAnimationFrame||e.msRequestAnimationFrame||function(e){setTimeout(e,1e3/60)},function(t){var n=o.createElement("style");n.type="text/css";try{n.appendChild(o.createTextNode(t))}catch(e){n.styleSheet.cssText=t}o.getElementsByTagName("head")[0].appendChild(n)}(".heart{width: 10px;height: 10px;position: fixed;background: #f00;transform: rotate(45deg);-webkit-transform: rotate(45deg);-moz-transform: rotate(45deg);}.heart:after,.heart:before{content: '';width: inherit;height: inherit;background: inherit;border-radius: 50%;-webkit-border-radius: 50%;-moz-border-radius: 50%;position: fixed;}.heart:after{top: -5px;}.heart:before{left: -5px;}"),a="function"==typeof e.onclick&&e.onclick,e.onclick=function(e){var t,n;a&&a(),t=e,(n=o.createElement("div")).className="heart",i.push({el:n,x:t.clientX-5,y:t.clientY-5,scale:1,alpha:1,color:"rgb("+~~(255*Math.random())+","+~~(255*Math.random())+","+~~(255*Math.random())+")"}),o.body.appendChild(n)},function e(){for(var t=0;t<i.length;t++)i[t].alpha<=0?(o.body.removeChild(i[t].el),i.splice(t,1)):(i[t].y--,i[t].scale+=.004,i[t].alpha-=.013,i[t].el.style.cssText="left:"+i[t].x+"px;top:"+i[t].y+"px;opacity:"+i[t].alpha+";transform:scale("+i[t].scale+","+i[t].scale+") rotate(45deg);background:"+i[t].color+";z-index:99999");requestAnimationFrame(e)}()}(window,document),function(){var e,t=document.title;document.addEventListener("visibilitychange",function(){document.hidden?(document.title="ฅ( •̀ .̫ •́ )ฅ 我藏起来了！",clearTimeout(e)):(document.title="(●'◡'●)被发现了!",e=setTimeout(function(){document.title=t},1e3))}),console.clear(),console.log("%c又特么来偷我代码？","background-image:-webkit-gradient( linear, left top, right top, color-stop(0, #f22), color-stop(0.15, #f2f), color-stop(0.3, #22f), color-stop(0.45, #2ff), color-stop(0.6, #2f2),color-stop(0.75, #2f2), color-stop(0.9, #ff2), color-stop(1, #f22) );color:transparent;-webkit-background-clip: text;font-size:2em;")}();var bar=1,line="|||||||||",amount="|";function count(){bar+=9,amount+=line,document.getElementById("chart").value=amount,document.getElementById("percent").value=bar+"%",bar<99?setTimeout("count()",100):document.getElementById("loading-wrap").style.display="none"}function go_high(){var e,n=["https://m7.music.126.net/20190410144840/5e92e5f61ae1ae183b27aa276782c68a/ymusic/035f/0659/0653/457d7520ab133721525719042895f037.mp3","https://m7.music.126.net/20190410145100/7724df29ab28e76d4932d857dc2a826b/ymusic/5ad8/3666/012a/91e5524b201c66380f2c385fc2200122.mp3",""];function t(e){var t,n={height:(t=e).offsetHeight,width:t.offsetWidth};return r<n.height&&n.height<c&&d<n.width&&n.width<l}function o(){for(var e=document.getElementsByClassName(u),t=new RegExp("\\b"+u+"\\b");0<e.length;)e[0].className=e[0].className.replace(t,"")}null===(e=document.getElementById("audio_element_id"))&&((e=document.createElement("audio")).setAttribute("class",g),e.setAttribute("curSongIndex",0),e.id="audio_element_id",e.loop=!1,e.bgcolor=0,e.addEventListener("canplay",function(){setTimeout(function(){w.className+=" "+u+" "+f},500),setTimeout(function(){var e;o(),(e=document.createElement("div")).setAttribute("class",p),document.body.appendChild(e),setTimeout(function(){document.body.removeChild(e)},100);for(var t=0;t<k.length;t++)k[t].className+=" "+u+" "+h[Math.floor(Math.random()*h.length)]},15500)},!0),e.addEventListener("ended",function(){o(),function(){for(var e=document.getElementsByClassName(g),t=0;t<e.length;t++)document.body.removeChild(e[t])}(),go()},!0),e.innerHTML=" <p>If you are reading this, it is because your browser does not support the audio element. We recommend that you get a new browser.</p> <p>",document.body.appendChild(e));for(var a,i,r=30,d=30,c=350,l=350,s=parseInt(document.getElementById("audio_element_id").getAttribute("curSongIndex")),m=n[s],u="mw-harlem_shake_me",f="im_first",h=["im_drunk","im_baked","im_trippin","im_blown"],p="mw-strobe_light",g="mw_added_css",b=(a=document.documentElement,window.innerWidth?window.innerHeight:a&&!isNaN(a.clientHeight)?a.clientHeight:0),y=window.pageYOffset?window.pageYOffset:Math.max(document.documentElement.scrollTop,document.body.scrollTop),v=document.getElementsByTagName("*"),w=null,x=0;x<v.length;x++){if(t(_=v[x])&&(void 0,i=function(e){for(var t=e,n=0;t;)n+=t.offsetTop,t=t.offsetParent;return n}(_),y<=i&&i<=b+y)){w=_;break}}if(null!==_){var E;(E=document.createElement("link")).setAttribute("type","text/css"),E.setAttribute("rel","stylesheet"),E.setAttribute("href","//s3.amazonaws.com/moovweb-marketing/playground/harlem-shake-style.css"),E.setAttribute("class",g),document.body.appendChild(E),function(){var e=document.getElementById("audio_element_id");if(null!=e){var t=parseInt(e.getAttribute("curSongIndex"));n.length-2<t?t=0:t++,e.setAttribute("curSongIndex",t),o()}e.src=m,e.play()}();var k=[];for(x=0;x<v.length;x++){var _;t(_=v[x])&&k.push(_)}}else console.warn("Could not find a node of the right size. Please try a different page.")}count();