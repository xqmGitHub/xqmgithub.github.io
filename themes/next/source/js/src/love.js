!function(e,t,a){function r(){for(var e=0;e<n.length;e++)n[e].alpha<=0?(t.body.removeChild(n[e].el),n.splice(e,1)):(n[e].y--,n[e].scale+=.004,n[e].alpha-=.013,n[e].el.style.cssText="left:"+n[e].x+"px;top:"+n[e].y+"px;opacity:"+n[e].alpha+";transform:scale("+n[e].scale+","+n[e].scale+") rotate(45deg);background:"+n[e].color+";z-index:99999");requestAnimationFrame(r)}var n=[];e.requestAnimationFrame=e.requestAnimationFrame||e.webkitRequestAnimationFrame||e.mozRequestAnimationFrame||e.oRequestAnimationFrame||e.msRequestAnimationFrame||function(e){setTimeout(e,1e3/60)},function(e){var a=t.createElement("style");a.type="text/css";try{a.appendChild(t.createTextNode(e))}catch(t){a.styleSheet.cssText=e}t.getElementsByTagName("head")[0].appendChild(a)}(".heart{width: 10px;height: 10px;position: fixed;background: #f00;transform: rotate(45deg);-webkit-transform: rotate(45deg);-moz-transform: rotate(45deg);}.heart:after,.heart:before{content: '';width: inherit;height: inherit;background: inherit;border-radius: 50%;-webkit-border-radius: 50%;-moz-border-radius: 50%;position: fixed;}.heart:after{top: -5px;}.heart:before{left: -5px;}"),function(){var a="function"==typeof e.onclick&&e.onclick;e.onclick=function(e){a&&a(),function(e){var a=t.createElement("div");a.className="heart",n.push({el:a,x:e.clientX-5,y:e.clientY-5,scale:1,alpha:1,color:"rgb("+~~(255*Math.random())+","+~~(255*Math.random())+","+~~(255*Math.random())+")"}),t.body.appendChild(a)}(e)}}(),r()}(window,document);
(function() {
    var OriginTitile = document.title, titleTime;
    document.addEventListener('visibilitychange', function() {
        if (document.hidden) {
            document.title = "ฅ( •̀ .̫ •́ )ฅ 我藏起来了！";
            clearTimeout(titleTime);
        } else {
            document.title = "(●'◡'●)被发现了!";
            titleTime = setTimeout(function() {
                document.title = OriginTitile;
            },1000);
        }
    });
	console.clear();
	console.log("%c又特么来偷我代码？", 'background-image:-webkit-gradient( linear, left top, right top, color-stop(0, #f22), color-stop(0.15, #f2f), color-stop(0.3, #22f), color-stop(0.45, #2ff), color-stop(0.6, #2f2),color-stop(0.75, #2f2), color-stop(0.9, #ff2), color-stop(1, #f22) );color:transparent;-webkit-background-clip: text;font-size:2em;');
})();
var bar = 1;
var line = "|||||||||";
var amount = "|";
count();
function count(){ 
	bar= bar + 9;
	amount = amount + line;
	document.getElementById('chart').value = amount;
	document.getElementById('percent').value = bar+"%"; 
	if (bar<99) {
		setTimeout("count()",100);
	}else {
		//document.getElementsByTagName('body')[0].removeChild(document.getElementById("loading-wrap"));
		//document.getElementById("loading-wrap").style.display="none"; 
		$("#loading-wrap").fadeOut(500);
	} 
}



function go_high() {
    var songs = [
        "https://m7.music.126.net/20190410144840/5e92e5f61ae1ae183b27aa276782c68a/ymusic/035f/0659/0653/457d7520ab133721525719042895f037.mp3",
        "https://m7.music.126.net/20190410145100/7724df29ab28e76d4932d857dc2a826b/ymusic/5ad8/3666/012a/91e5524b201c66380f2c385fc2200122.mp3",
        ""
    ];
    function c() {
        var e = document.createElement("link");
        e.setAttribute("type", "text/css");
        e.setAttribute("rel", "stylesheet");
        e.setAttribute("href", f);
        e.setAttribute("class", l);
        document.body.appendChild(e)
    }
    function h() {
        var e = document.getElementsByClassName(l);
        for (var t = 0; t < e.length; t++) {
            document.body.removeChild(e[t])
        }
    }
    function p() {
        var e = document.createElement("div");
        e.setAttribute("class", a);
        document.body.appendChild(e);
        setTimeout(function() {
            document.body.removeChild(e)
        }, 100)
    }
    function d(e) {
        return {
            height : e.offsetHeight,
            width : e.offsetWidth
        }
    }
    function v(i) {
        var s = d(i);
        return s.height > e && s.height < n && s.width > t && s.width < r
    }
    function m(e) {
        var t = e;
        var n = 0;
        while (!!t) {
            n += t.offsetTop;
            t = t.offsetParent
        }
        return n
    }
    function g() {
        var e = document.documentElement;
        if (!!window.innerWidth) {
            return window.innerHeight
        } else if (e && !isNaN(e.clientHeight)) {
            return e.clientHeight
        }
        return 0
    }
    function y() {
        if (window.pageYOffset) {
            return window.pageYOffset
        }
        return Math.max(document.documentElement.scrollTop, document.body.scrollTop)
    }
    function E(e) {
        var t = m(e);
        return t >= w && t <= b + w
    }
    function S() {
        var e = document.getElementById("audio_element_id");
        if(e != null){
            var index = parseInt(e.getAttribute("curSongIndex"));
            if(index > songs.length - 2) {
                index = 0;
            } else {
                index++;
            }
            e.setAttribute("curSongIndex", index);
            N();
        }
        e.src = i;
        e.play()
    }
    function x(e) {
        e.className += " " + s + " " + o
    }
    function T(e) {
        e.className += " " + s + " " + u[Math.floor(Math.random() * u.length)]
    }
    function N() {
        var e = document.getElementsByClassName(s);
        var t = new RegExp("\\b" + s + "\\b");
        for (var n = 0; n < e.length; ) {
            e[n].className = e[n].className.replace(t, "")
        }
    }
    function initAudioEle() {
        var e = document.getElementById("audio_element_id");
        if(e === null){
            e = document.createElement("audio");
            e.setAttribute("class", l);
            e.setAttribute("curSongIndex", 0);
            e.id = "audio_element_id";
            e.loop = false;
            e.bgcolor = 0;
            e.addEventListener("canplay", function() {
                setTimeout(function() {
                    x(k)
                }, 500);
                setTimeout(function() {
                    N();
                    p();
                    for (var e = 0; e < O.length; e++) {
                        T(O[e])
                    }
                }, 15500)
            }, true);
            e.addEventListener("ended", function() {
                N();
                h();
                go();
            }, true);
            e.innerHTML = " <p>If you are reading this, it is because your browser does not support the audio element. We recommend that you get a new browser.</p> <p>";
            document.body.appendChild(e);
        }
    }
    initAudioEle();
    var e = 30;
    var t = 30;
    var n = 350;
    var r = 350;

    var curSongIndex = parseInt(document.getElementById("audio_element_id").getAttribute("curSongIndex"));
    var i = songs[curSongIndex];

    var s = "mw-harlem_shake_me";
    var o = "im_first";
    var u = ["im_drunk", "im_baked", "im_trippin", "im_blown"];
    var a = "mw-strobe_light";

    /* harlem-shake-style.css，替换成你的位置，也可以直接使用：//s3.amazonaws.com/moovweb-marketing/playground/harlem-shake-style.css */
    var f = "//s3.amazonaws.com/moovweb-marketing/playground/harlem-shake-style.css";

    var l = "mw_added_css";
    var b = g();
    var w = y();
    var C = document.getElementsByTagName("*");
    var k = null;
    for (var L = 0; L < C.length; L++) {
        var A = C[L];
        if (v(A)) {
            if (E(A)) {
                k = A;
                break
            }
        }
    }
    if (A === null) {
        console.warn("Could not find a node of the right size. Please try a different page.");
        return
    }
    c();
    S();
    var O = [];
    for (var L = 0; L < C.length; L++) {
        var A = C[L];
        if (v(A)) {
            O.push(A)
        }
    }
}


var onPopupClose = function (e) {
    $('.popup').hide();
    $('#local-search-input').val('');
    $('.search-result-list').remove();
    $('#no-result').remove();
    $(".local-search-pop-overlay").remove();
    $('body').css('overflow', '');
}

function proceedsearch() {
    $("body")
        .append('<div class="search-popup-overlay local-search-pop-overlay"></div>')
        .css('overflow', 'hidden');
    $('.search-popup-overlay').click(onPopupClose);
    $('.popup').toggle();
    var $localSearchInput = $('#local-search-input');
    $localSearchInput.attr("autocapitalize", "none");
    $localSearchInput.attr("autocorrect", "off");
    $localSearchInput.focus();
}

// search function;
var searchFunc = function(path, search_id, content_id) {
    'use strict';

    // start loading animation
    $("body")
        .append('<div class="search-popup-overlay local-search-pop-overlay">' +
            '<div id="search-loading-icon">' +
            '<i class="fa fa-spinner fa-pulse fa-5x fa-fw"></i>' +
            '</div>' +
            '</div>')
        .css('overflow', 'hidden');
    $("#search-loading-icon").css('margin', '20% auto 0 auto').css('text-align', 'center');

    var searchTextCount = 0;
    $.ajax({
        url: path,
        dataType: isXml ? "xml" : "json",
        async: true,
        success: function(res) {
            // get the contents from search data
            isfetched = true;
            $('.popup').detach().appendTo('.header-inner');
            var datas = isXml ? $("entry", res).map(function() {
                return {
                    title: $("title", this).text(),
                    content: $("content",this).text(),
                    url: $("url" , this).text()
                };
            }).get() : res;
            var input = document.getElementById(search_id);
            var resultContent = document.getElementById(content_id);
            var inputEventFunction = function() {
                var searchText = input.value.trim().toLowerCase();
                var keywords = searchText.split(/[\s\-]+/);
                if (keywords.length > 1) {
                    keywords.push(searchText);
                }
                var resultItems = [];
                if (searchText.length > 0) {
                    // perform local searching
                    datas.forEach(function(data) {
                        var isMatch = false;
                        var hitCount = 0;
                        var title = data.title.trim();
                        var titleInLowerCase = title.toLowerCase();
                        var content = data.content.trim().replace(/<[^>]+>/g,"");
                        var contentInLowerCase = content.toLowerCase();
                        var articleUrl = decodeURIComponent(data.url);
                        var indexOfTitle = [];
                        var indexOfContent = [];
                        // only match articles with not empty titles
                        if(title != '') {
                            keywords.forEach(function(keyword) {
                                function getIndexByWord(word, text, caseSensitive) {
                                    var wordLen = word.length;
                                    if (wordLen === 0) {
                                        return [];
                                    }
                                    var startPosition = 0, position = [], index = [];
                                    if (!caseSensitive) {
                                        text = text.toLowerCase();
                                        word = word.toLowerCase();
                                    }
                                    while ((position = text.indexOf(word, startPosition)) > -1) {
                                        index.push({position: position, word: word});
                                        startPosition = position + wordLen;
                                    }
                                    return index;
                                }

                                indexOfTitle = indexOfTitle.concat(getIndexByWord(keyword, titleInLowerCase, false));
                                indexOfContent = indexOfContent.concat(getIndexByWord(keyword, contentInLowerCase, false));
                            });
                            if (indexOfTitle.length > 0 || indexOfContent.length > 0) {
                                isMatch = true;
                                hitCount = indexOfTitle.length + indexOfContent.length;
                            }
                        }

                        // show search results

                        if (isMatch) {
                            // sort index by position of keyword

                            [indexOfTitle, indexOfContent].forEach(function (index) {
                                index.sort(function (itemLeft, itemRight) {
                                    if (itemRight.position !== itemLeft.position) {
                                        return itemRight.position - itemLeft.position;
                                    } else {
                                        return itemLeft.word.length - itemRight.word.length;
                                    }
                                });
                            });

                            // merge hits into slices function mergeIntoSlice


                            var slicesOfTitle = [];
                            if (indexOfTitle.length != 0) {
                                slicesOfTitle.push(mergeIntoSlice(title, 0, title.length, indexOfTitle));
                            }

                            var slicesOfContent = [];
                            while (indexOfContent.length != 0) {
                                var item = indexOfContent[indexOfContent.length - 1];
                                var position = item.position;
                                var word = item.word;
                                // cut out 100 characters
                                var start = position - 20;
                                var end = position + 80;
                                if(start < 0){
                                    start = 0;
                                }
                                if (end < position + word.length) {
                                    end = position + word.length;
                                }
                                if(end > content.length){
                                    end = content.length;
                                }
                                slicesOfContent.push(mergeIntoSlice(content, start, end, indexOfContent));
                            }

                            // sort slices in content by search text's count and hits' count

                            slicesOfContent.sort(function (sliceLeft, sliceRight) {
                                if (sliceLeft.searchTextCount !== sliceRight.searchTextCount) {
                                    return sliceRight.searchTextCount - sliceLeft.searchTextCount;
                                } else if (sliceLeft.hits.length !== sliceRight.hits.length) {
                                    return sliceRight.hits.length - sliceLeft.hits.length;
                                } else {
                                    return sliceLeft.start - sliceRight.start;
                                }
                            });

                            // select top N slices in content

                            var upperBound = parseInt('{{ theme.local_search.top_n_per_article }}');
                            if (upperBound >= 0) {
                                slicesOfContent = slicesOfContent.slice(0, upperBound);
                            }

                            // highlight title and content function highlightKeyword

                            var resultItem = '';

                            if (slicesOfTitle.length != 0) {
                                resultItem += "<li><a href='" + articleUrl + "' class='search-result-title'>" + highlightKeyword(title, slicesOfTitle[0]) + "</a>";
                            } else {
                                resultItem += "<li><a href='" + articleUrl + "' class='search-result-title'>" + title + "</a>";
                            }

                            slicesOfContent.forEach(function (slice) {
                                resultItem += "<a href='" + articleUrl + "'>" +
                                    "<p class=\"search-result\">" + highlightKeyword(content, slice) +
                                    "...</p>" + "</a>";
                            });

                            resultItem += "</li>";
                            resultItems.push({
                                item: resultItem,
                                searchTextCount: searchTextCount,
                                hitCount: hitCount,
                                id: resultItems.length
                            });
                        }
                    })
                };
                if (keywords.length === 1 && keywords[0] === "") {
                    resultContent.innerHTML = '<div id="no-result"><i class="fa fa-search fa-5x" /></div>'
                } else if (resultItems.length === 0) {
                    resultContent.innerHTML = '<div id="no-result"><i class="fa fa-frown-o fa-5x" /></div>'
                } else {
                    resultItems.sort(function (resultLeft, resultRight) {
                        if (resultLeft.searchTextCount !== resultRight.searchTextCount) {
                            return resultRight.searchTextCount - resultLeft.searchTextCount;
                        } else if (resultLeft.hitCount !== resultRight.hitCount) {
                            return resultRight.hitCount - resultLeft.hitCount;
                        } else {
                            return resultRight.id - resultLeft.id;
                        }
                    });
                    var searchResultList = '<ul class=\"search-result-list\">';
                    resultItems.forEach(function (result) {
                        searchResultList += result.item;
                    })
                    searchResultList += "</ul>";
                    resultContent.innerHTML = searchResultList;
                }
            }

            if ('auto' === '{{ theme.local_search.trigger }}') {
                input.addEventListener('input', inputEventFunction);
            } else {
                $('.search-icon').click(inputEventFunction);
                input.addEventListener('keypress', function (event) {
                    if (event.keyCode === 13) {
                        inputEventFunction();
                    }
                });
            }

            // remove loading animation
            $(".local-search-pop-overlay").remove();
            $('body').css('overflow', '');

            proceedsearch();
        }
    });

    // merge hits into slices
    function mergeIntoSlice(text, start, end, index) {
        var item = index[index.length - 1];
        var position = item.position;
        var word = item.word;
        var hits = [];
        var searchTextCountInSlice = 0;
        while (position + word.length <= end && index.length != 0) {
            if (word === searchText) {
                searchTextCountInSlice++;
            }
            hits.push({position: position, length: word.length});
            var wordEnd = position + word.length;

            // move to next position of hit

            index.pop();
            while (index.length != 0) {
                item = index[index.length - 1];
                position = item.position;
                word = item.word;
                if (wordEnd > position) {
                    index.pop();
                } else {
                    break;
                }
            }
        }
        searchTextCount += searchTextCountInSlice;
        return {
            hits: hits,
            start: start,
            end: end,
            searchTextCount: searchTextCountInSlice
        };
    }

// highlight title and content
    function highlightKeyword(text, slice) {
        var result = '';
        var prevEnd = slice.start;
        slice.hits.forEach(function (hit) {
            result += text.substring(prevEnd, hit.position);
            var end = hit.position + hit.length;
            result += '<b class="search-keyword">' + text.substring(hit.position, end) + '</b>';
            prevEnd = end;
        });
        result += text.substring(prevEnd, slice.end);
        return result;
    }
}



// handle and trigger popup window;
$('.popup-trigger').click(function(e) {
    e.stopPropagation();
    if (isfetched === false) {
        searchFunc(path, 'local-search-input', 'local-search-result');
    } else {
        proceedsearch();
    };
});

$('.popup-btn-close').click(onPopupClose);
$('.popup').click(function(e){
    e.stopPropagation();
});
$(document).on('keyup', function (event) {
    var shouldDismissSearchPopup = event.which === 27 &&
        $('.search-popup').is(':visible');
    if (shouldDismissSearchPopup) {
        onPopupClose();
    }
});