# ===============================================================
# ========================= ATTENTION! ==========================
# ===============================================================
# NexT repository is moving here: https://github.com/theme-next
# ===============================================================
# It's rebase to v6.0.0 and future maintenance will resume there
# ===============================================================

# ---------------------------------------------------------------
# Theme Core Configuration Settings
# ---------------------------------------------------------------

# Set to true, if you want to fully override the default configuration.
# Useful if you don't want to inherit the theme _config.yml configurations.
override: false

# ---------------------------------------------------------------
# Site Information Settings
# ---------------------------------------------------------------

# To get or check favicons visit: https://realfavicongenerator.net
# Put your favicons into `hexo-site/source/` (recommend) or `hexo-site/themes/next/source/images/` directory.

# Default NexT favicons placed in `hexo-site/themes/next/source/images/` directory.
# And if you want to place your icons in `hexo-site/source/` root directory, you must remove `/images` prefix from pathes.

# For example, you put your favicons into `hexo-site/source/images` directory.
# Then need to rename & redefine they on any other names, otherwise icons from Next will rewrite your custom icons in Hexo.
favicon:
  small: /favicon.ico
  medium: /favicon.ico
  apple_touch_icon: /favicon.ico
  safari_pinned_tab: /favicon.ico
  #android_manifest: /images/manifest.json
  #ms_browserconfig: /images/browserconfig.xml

# Set default keywords (Use a comma to separate)
keywords: "Hexo, NexT"

# Set rss to false to disable feed link.
# Leave rss as empty to use site's feed link.
# Set rss to specific value if you have burned your feed already.
rss:

footer:
  # 页脚配置
  # Specify the date when the site was setup.
  # If not defined, current year will be used.
  # 建站年份
  since: 2018

  # Icon between year and copyright info.
  # 年份后面的图标，为 Font Awesome 图标
  # 自己去纠结 http://fontawesome.io/icons/
  # 然后更改名字就行，下面的有关图标的设置都一样
  icon: heart

  # If not defined, will be used `author` from Hexo main config.
  # 如果不定义，默认用站点配置文件的 author 名
  copyright:
  # -------------------------------------------------------------
  # Hexo link (Powered by Hexo).
  powered: false

  theme:
    # Theme & scheme info link (Theme - NexT.scheme).
    enable: false
    # Version info of NexT after scheme info (vX.X.X).
    version: false
  # -------------------------------------------------------------
  # Any custom text can be defined here.
  #custom_text: Hosted by <a target="_blank" href="https://pages.github.com">GitHub Pages</a>

# ---------------------------------------------------------------
# SEO Settings
# ---------------------------------------------------------------

# Canonical, set a canonical link tag in your hexo, you could use it for your SEO of blog.
# See: https://support.google.com/webmasters/answer/139066
# Tips: Before you open this tag, remember set up your URL in hexo _config.yml ( ex. url: http://yourdomain.com )
canonical: true

# Change headers hierarchy on site-subtitle (will be main site description) and on all post/pages titles for better SEO-optimization.
seo: false

# If true, will add site-subtitle to index page, added in main hexo config.
# subtitle: Subtitle
index_with_subtitle: false


# ---------------------------------------------------------------
# Menu Settings
# ---------------------------------------------------------------

# When running the site in a subdirectory (e.g. domain.tld/blog), remove the leading slash from link value (/archives -> archives).
# Usage: `Key: /link/ || icon`
# Key is the name of menu item. If translate for this menu will find in languages - this translate will be loaded; if not - Key name will be used. Key is case-senstive.
# Value before `||` delimeter is the target link.
# Value after `||` delimeter is the name of FontAwesome icon. If icon (with or without delimeter) is not specified, question icon will be loaded.

# 菜单设置 || 菜单图标设置（图标上面说了，不重复）
# 项目换行可以更改显示顺序
# 如果这个项前会显示 .menu
# 解决方法：编辑 ~/blog/themes/next/languages 下的相应文件
# 比如添加一个“留言”菜单，站点配置文件的 language 是 zh-Hans
# 则编辑 zh-Hans.yml，在 menu: 项内添加一行 留言: 留言
# 注意空格，且符号 : 为英文字符！
menu:
  home: / || home
  archives: /archives/ || archive
  #about: /about/ || user
  tags: /tags/ || tags
  categories: /categories/ || th
  #schedule: /schedule/ || calendar
  #sitemap: /sitemap.xml || sitemap
  #commonweal: /404/ || heartbeat

# Enable/Disable menu icons.
# 是否开启菜单图标
menu_icons:
  enable: true


# ---------------------------------------------------------------
# Scheme Settings
# ---------------------------------------------------------------

# Schemes
#scheme: Muse
#scheme: Mist
scheme: Pisces
#scheme: Gemini


# ---------------------------------------------------------------
# Sidebar Settings
# ---------------------------------------------------------------

# Social Links.
# Usage: `Key: permalink || icon`
# Key is the link label showing to end users.
# Value before `||` delimeter is the target permalink.
# Value after `||` delimeter is the name of FontAwesome icon. If icon (with or without delimeter) is not specified, globe icon will be loaded.
# 侧栏社交链接设置，与上面菜单差不多，要生效记得把前面的 # 去掉
#social:
  #GitHub: https://github.com/yourname || github
  #E-Mail: mailto:yourname@gmail.com || envelope
  #Google: https://plus.google.com/yourname || google
  #Twitter: https://twitter.com/yourname || twitter
  #FB Page: https://www.facebook.com/yourname || facebook
  #VK Group: https://vk.com/yourname || vk
  #StackOverflow: https://stackoverflow.com/yourname || stack-overflow
  #YouTube: https://youtube.com/yourname || youtube
  #Instagram: https://instagram.com/yourname || instagram
  #Skype: skype:yourname?call|chat || skype

social_icons:
  enable: true
  icons_only: false
  transition: false

# Blog rolls
# 侧栏友链设置
#links_icon: globe
#links_title: 神奇的链接
#links_layout: block
#links_layout: inline
#links:
  #Title: http://example.com/

# Sidebar Avatar
# in theme directory(source/images): /images/avatar.gif
# in site  directory(source/uploads): /uploads/avatar.gif
# avatar: /images/my_avatar.gif
avatar: http://p5tq1m3a9.bkt.clouddn.com/hexo_blog/static/my_avatar.gif

# Table Of Contents in the Sidebar
toc:
  enable: true

  # Automatically add list number to toc.
  number: true

  # If true, all words will placed on next lines if header width longer then sidebar width.
  wrap: false

# Creative Commons 4.0 International License.
# http://creativecommons.org/
# Available: by | by-nc | by-nc-nd | by-nc-sa | by-nd | by-sa | zero
#creative_commons: by-nc-sa
#creative_commons:

sidebar:
  # Sidebar Position, available value: left | right (only for Pisces | Gemini).
  # 侧栏位置设置，可用值：左 | 右（只对 Pisces 和 Gemini 设计版式有效！）
  position: left
  #position: right

  # Sidebar Display, available value (only for Muse | Mist):
  #  - post    expand on posts automatically. Default.
  #  - always  expand for all pages automatically
  #  - hide    expand only when click on the sidebar toggle icon.
  #  - remove  Totally remove sidebar including sidebar toggle.
  # 侧栏显示方式，post 代表只有点进一篇文章内
  # 且文章有目录，侧栏才会弹出显示
  #display: post
  #display: always
  display: hide
  #display: remove

  # Sidebar offset from top menubar in pixels (only for Pisces | Gemini).
  offset: 12

  # Back to top in sidebar (only for Pisces | Gemini).
  b2t: false

  # Scroll percent label in b2t button.
  # 在回到顶部按钮里显示阅读百分比
  scrollpercent: false

  # Enable sidebar on narrow view (only for Muse | Mist).
  # 移动端显示侧栏，只对 Muse 和 Mist 设计版式有效！
  onmobile: true


# ---------------------------------------------------------------
# Post Settings
# ---------------------------------------------------------------

# Automatically scroll page to section which is under <!-- more --> mark.
# 点击 [Read More]，页面自动滚动到 <!-- more --> 标记处
scroll_to_more: false

# Automatically saving scroll position on each post/page in cookies.
# 用 cookies 保存浏览的位置信息，意味着重新打开这个页面后
# 页面就会自动滚动到上次的位置，除非读者清理浏览器 cookies
save_scroll: false

# Automatically excerpt description in homepage as preamble text.
excerpt_description: true

# Automatically Excerpt. Not recommend.
# Please use <!-- more --> in the post to control excerpt accurately.
# 按字数自动加入 [Read More]，不建议！
# 建议在文章中加入 <!-- more -->
# 自定义 [Read More] 按钮之前要显示的内容！
auto_excerpt:
  enable: false
  length: 150

# Post meta display settings
# 文章顶部显示的文章元数据设置
post_meta:
  item_text: true
  created_at: true
  updated_at: false
  categories: true

# Post wordcount display settings
# Dependencies: https://github.com/willin/hexo-wordcount
# 显示统计字数和估计阅读时长
# 注意：这个要安装插件，先进入站点文件夹根目录
# 然后：npm install hexo-wordcount --save
post_wordcount:
  item_text: true
  wordcount: false
  min2read: false
  totalcount: false
  separated_meta: true

# Wechat Subscriber
#wechat_subscriber:
  #enabled: true
  #qcode: /path/to/your/wechatqcode ex. /uploads/wechat-qcode.jpg
  #description: ex. subscribe to my blog by scanning my public wechat account

# Reward
reward_comment: ✨💖✨
wechatpay: http://p5tq1m3a9.bkt.clouddn.com/hexo_blog/static/wechatpay.png
alipay: http://p5tq1m3a9.bkt.clouddn.com/hexo_blog/static/alipay.jpg

#wechatpay: /images/wechatpay.jpg
#alipay: /images/alipay.jpg
#bitcoin: /images/bitcoin.png

# Declare license on posts
post_copyright:
  enable: false
  license: CC BY-NC-SA 3.0
  license_url: https://creativecommons.org/licenses/by-nc-sa/3.0/


# ---------------------------------------------------------------
# Misc Theme Settings
# ---------------------------------------------------------------

# Reduce padding / margin indents on devices with narrow width.
mobile_layout_economy: false

# Android Chrome header panel color ($black-deep).
# Android 上 Chrome 浏览器顶部颜色设置
android_chrome_color: "#222"

# Custom Logo.
# !!Only available for Default Scheme currently.
# Options:
#   enabled: [true/false] - Replace with specific image
#   image: url-of-image   - Images's url
custom_logo:
  enabled: false
  image:

# Code Highlight theme
# Available value:
#    normal | night | night eighties | night blue | night bright
# https://github.com/chriskempson/tomorrow-theme
highlight_theme: normal

# ---------------------------------------------------------------
# Font Settings
# - Find fonts on Google Fonts (https://www.google.com/fonts)
# - All fonts set here will have the following styles:
#     light, light italic, normal, normal italic, bold, bold italic
# - Be aware that setting too much fonts will cause site running slowly
# - Introduce in 5.0.1
# ---------------------------------------------------------------
# CAUTION! Safari Version 10.1.2 bug: https://github.com/iissnan/hexo-theme-next/issues/1844
# To avoid space between header and sidebar in Pisces / Gemini themes recommended to use Web Safe fonts for `global` (and `logo`):
# Arial | Tahoma | Helvetica | Times New Roman | Courier New | Verdana | Georgia | Palatino | Garamond | Comic Sans MS | Trebuchet MS
# ---------------------------------------------------------------
font:
  enable: false

  # Uri of fonts host. E.g. //fonts.googleapis.com (Default).
  host:

  # Font options:
  # `external: true` will load this font family from `host` above.
  # `family: Times New Roman`. Without any quotes.
  # `size: xx`. Use `px` as unit.

  # Global font settings used on <body> element.
  global:
    external: true
    family: Lato
    size:

  # Font settings for Headlines (h1, h2, h3, h4, h5, h6).
  # Fallback to `global` font settings.
  headings:
    external: true
    family:
    size:

  # Font settings for posts.
  # Fallback to `global` font settings.
  posts:
    external: true
    family:

  # Font settings for Logo.
  # Fallback to `global` font settings.
  logo:
    external: true
    family:
    size:

  # Font settings for <code> and code blocks.
  codes:
    external: true
    family:
    size:


# ---------------------------------------------------------------
# Third Party Services Settings
# ---------------------------------------------------------------

# MathJax Support
mathjax:
  enable: false
  per_page: false
  cdn:

# Han Support docs: https://hanzi.pro/
han: false

# Swiftype Search API Key
#swiftype_key:

# Baidu Analytics ID
#baidu_analytics:

# Duoshuo ShortName
#duoshuo_shortname:

# Disqus
disqus:
  enable: false
  shortname:
  count: true

# Hypercomments
#hypercomments_id:

# changyan
changyan:
  enable: false
  appid:
  appkey:


# Valine.
# You can get your appid and appkey from https://leancloud.cn
# more info please open https://valine.js.org
valine:
  enable: false
  appid:  # your leancloud application appid
  appkey:  # your leancloud application appkey
  notify: false # mail notifier , https://github.com/xCss/Valine/wiki
  verify: false # Verification code
  placeholder: Just go go # comment box placeholder
  avatar: mm # gravatar style
  guest_info: nick,mail,link # custom comment header
  pageSize: 10 # pagination size


# Support for youyan comments system.
# You can get your uid from http://www.uyan.cc
#youyan_uid: your uid

# Support for LiveRe comments system.
# You can get your uid from https://livere.com/insight/myCode (General web site)
# 来必力 评论插件
livere_uid: MTAyMC8zMzY4Ny8xMDI0Mg==

# Gitment
# Introduction: https://imsun.net/posts/gitment-introduction/
# You can get your Github ID from https://api.github.com/users/<Github username>
gitment:
  enable: false
  mint: true # RECOMMEND, A mint on Gitment, to support count, language and proxy_gateway
  count: true # Show comments count in post meta area
  lazy: false # Comments lazy loading with a button
  cleanly: false # Hide 'Powered by ...' on footer, and more
  language: # Force language, or auto switch by theme
  github_user: # MUST HAVE, Your Github ID
  github_repo: # MUST HAVE, The repo you use to store Gitment comments
  client_id: # MUST HAVE, Github client id for the Gitment
  client_secret: # EITHER this or proxy_gateway, Github access secret token for the Gitment
  proxy_gateway: # Address of api proxy, See: https://github.com/aimingoo/intersect
  redirect_protocol: # Protocol of redirect_uri with force_redirect_protocol when mint enabled

# Baidu Share
# Available value:
#    button | slide
# Warning: Baidu Share does not support https.
#baidushare:
##  type: button

# Share
# This plugin is more useful in China, make sure you known how to use it.
# And you can find the use guide at official webiste: http://www.jiathis.com/.
# Warning: JiaThis does not support https.
#jiathis:
  ##uid: Get this uid from http://www.jiathis.com/
#add_this_id:

# Share
#duoshuo_share: true

# NeedMoreShare2
# This plugin is a pure javascript sharing lib which is useful in China.
# See: https://github.com/revir/need-more-share2
# Also see: https://github.com/DzmVasileusky/needShareButton
# iconStyle: default | box
# boxForm: horizontal | vertical
# position: top / middle / bottom + Left / Center / Right
# networks: Weibo,Wechat,Douban,QQZone,Twitter,Linkedin,Mailto,Reddit,
#           Delicious,StumbleUpon,Pinterest,Facebook,GooglePlus,Slashdot,
#           Technorati,Posterous,Tumblr,GoogleBookmarks,Newsvine,
#           Evernote,Friendfeed,Vkontakte,Odnoklassniki,Mailru
needmoreshare2:
  enable: true
  postbottom:
    enable: true
    options:
      iconStyle: box
      boxForm: horizontal
      position: bottomCenter
      networks: Weibo,Wechat,Douban,QQZone,Twitter,Facebook
  float:
    enable: false
    options:
      iconStyle: box
      boxForm: horizontal
      position: middleRight
      networks: Weibo,Wechat,Douban,QQZone,Twitter,Facebook

# Google Webmaster tools verification setting
# See: https://www.google.com/webmasters/
#google_site_verification:

# Google Analytics
#google_analytics:

# Bing Webmaster tools verification setting
# See: https://www.bing.com/webmaster/
#bing_site_verification:

# Yandex Webmaster tools verification setting
# See: https://webmaster.yandex.ru/
#yandex_site_verification:

# CNZZ count
#cnzz_siteid:

# Application Insights
# See https://azure.microsoft.com/en-us/services/application-insights/
# application_insights:

# Make duoshuo show UA
# user_id must NOT be null when admin_enable is true!
# you can visit http://dev.duoshuo.com get duoshuo user id.
duoshuo_info:
  ua_enable: true
  admin_enable: false
  user_id: 0
  #admin_nickname: Author

# Post widgets & FB/VK comments settings.
# ---------------------------------------------------------------
# Facebook SDK Support.
# https://github.com/iissnan/hexo-theme-next/pull/410
facebook_sdk:
  enable:       false
  app_id:       #<app_id>
  fb_admin:     #<user_id>
  like_button:  #true
  webmaster:    #true

# Facebook comments plugin
# This plugin depends on Facebook SDK.
# If facebook_sdk.enable is false, Facebook comments plugin is unavailable.
facebook_comments_plugin:
  enable:       false
  num_of_posts: 10    # min posts num is 1
  width:        100%  # default width is 550px
  scheme:       light # default scheme is light (light or dark)

# VKontakte API Support.
# To get your AppID visit https://vk.com/editapp?act=create
vkontakte_api:
  enable:       false
  app_id:       #<app_id>
  like:         true
  comments:     true
  num_of_posts: 10

# Star rating support to each article.
# To get your ID visit https://widgetpack.com
rating:
  enable: false
  id:     #<app_id>
  color:  fc6423
# ---------------------------------------------------------------

# Show number of visitors to each article.
# You can visit https://leancloud.cn get AppID and AppKey.
leancloud_visitors:
  enable: true
  app_id: ICqTf6gHem5BpwwPYwCi3brE-gzGzoHsz
  app_key: 2SrfjFRdeTPlzqyLBlCLYhuN

# Another tool to show number of visitors to each article.
# visit https://console.firebase.google.com/u/0/ to get apiKey and projectId
# visit https://firebase.google.com/docs/firestore/ to get more information about firestore
firestore:
  enable: false
  collection: articles #required, a string collection name to access firestore database
  apiKey: #required
  projectId: #required
  bluebird: false #enable this if you want to include bluebird 3.5.1(core version) Promise polyfill

# Show PV/UV of the website/page with busuanzi.
# Get more information on http://ibruce.info/2015/04/04/busuanzi/
# 不蒜子统计，用于在页脚显示总访客数和总浏览量，将 false 改为 true 就能直接使用
busuanzi_count:
  # count values only if the other configs are false
  enable: true
  # custom uv span for the whole site
  site_uv: true
  site_uv_header: <i class="fa fa-user"></i>
  site_uv_footer:
  # custom pv span for the whole site
  site_pv: true
  site_pv_header: <i class="fa fa-eye"></i>
  site_pv_footer:
  # custom pv span for one page only
  # custom pv span for one page only
  # 页面浏览量，不建议开启，建议用上面的 leancloud_visitors
  # 首先 leancloud 更稳定，其次 leancloud 便于管理
  # 最后，可以利用 leancloud 的 api 建立 TopX 页面
  page_pv: false
  page_pv_header: <i class="fa fa-file-o"></i>
  page_pv_footer:


# Tencent analytics ID
# tencent_analytics:

# Tencent MTA ID
# tencent_mta:


# Enable baidu push so that the blog will push the url to baidu automatically which is very helpful for SEO
baidu_push: true

# Google Calendar
# Share your recent schedule to others via calendar page
#
# API Documentation:
# https://developers.google.com/google-apps/calendar/v3/reference/events/list
calendar:
  enable: false
  calendar_id: <required>
  api_key: <required>
  orderBy: startTime
  offsetMax: 24
  offsetMin: 4
  timeZone:
  showDeleted: false
  singleEvents: true
  maxResults: 250

# Algolia Search
algolia_search:
  enable: false
  hits:
    per_page: 10
  labels:
    input_placeholder: Search for Posts
    hits_empty: "We didn't find any results for the search: ${query}"
    hits_stats: "${hits} results found in ${time} ms"

# Local search
# Dependencies: https://github.com/flashlab/hexo-generator-search
local_search:
  enable: true
  # if auto, trigger search by changing input
  # if manual, trigger search by pressing enter key or search button
  trigger: auto
  # show top n results per article, show all results by setting to -1
  top_n_per_article: 1


# ---------------------------------------------------------------
# Tags Settings
# ---------------------------------------------------------------

# External URL with BASE64 encrypt & decrypt.
# Usage: {% exturl text url "title" %}
# Alias: {% extlink text url "title" %}
exturl: false

# Note tag (bs-callout).
note:
  # Note tag style values:
  #  - simple    bs-callout old alert style. Default.
  #  - modern    bs-callout new (v2-v3) alert style.
  #  - flat      flat callout style with background, like on Mozilla or StackOverflow.
  #  - disabled  disable all CSS styles import of note tag.
  style: simple
  icons: false
  border_radius: 3
  # Offset lighter of background in % for modern and flat styles (modern: -12 | 12; flat: -18 | 6).
  # Offset also applied to label tag variables. This option can work with disabled note tag.
  light_bg_offset: 0

# Label tag.
label: true

# Tabs tag.
tabs:
  enable: true
  transition:
    tabs: false
    labels: true
  border_radius: 0


#! ---------------------------------------------------------------
#! DO NOT EDIT THE FOLLOWING SETTINGS
#! UNLESS YOU KNOW WHAT YOU ARE DOING
#! ---------------------------------------------------------------

# Use velocity to animate everything.
motion:
  enable: true
  async: false
  transition:
    # Transition variants:
    # fadeIn | fadeOut | flipXIn | flipXOut | flipYIn | flipYOut | flipBounceXIn | flipBounceXOut | flipBounceYIn | flipBounceYOut
    # swoopIn | swoopOut | whirlIn | whirlOut | shrinkIn | shrinkOut | expandIn | expandOut
    # bounceIn | bounceOut | bounceUpIn | bounceUpOut | bounceDownIn | bounceDownOut | bounceLeftIn | bounceLeftOut | bounceRightIn | bounceRightOut
    # slideUpIn | slideUpOut | slideDownIn | slideDownOut | slideLeftIn | slideLeftOut | slideRightIn | slideRightOut
    # slideUpBigIn | slideUpBigOut | slideDownBigIn | slideDownBigOut | slideLeftBigIn | slideLeftBigOut | slideRightBigIn | slideRightBigOut
    # perspectiveUpIn | perspectiveUpOut | perspectiveDownIn | perspectiveDownOut | perspectiveLeftIn | perspectiveLeftOut | perspectiveRightIn | perspectiveRightOut
    post_block: fadeIn
    post_header: slideDownIn
    post_body: slideDownIn
    coll_header: slideLeftIn
    # Only for Pisces | Gemini.
    sidebar: slideUpIn

# Fancybox
# 查看图片的
fancybox: true

# Progress bar in the top during page loading.
pace: true
# Themes list:
#pace-theme-big-counter
#pace-theme-bounce
#pace-theme-barber-shop
#pace-theme-center-atom
#pace-theme-center-circle
#pace-theme-center-radar
#pace-theme-center-simple
#pace-theme-corner-indicator
#pace-theme-fill-left
#pace-theme-flash
#pace-theme-loading-bar
#pace-theme-mac-osx
#pace-theme-minimal
# For example
# pace_theme: pace-theme-center-simple
pace_theme: pace-theme-minimal

# Canvas-nest
canvas_nest: false

# three_waves
three_waves: false

# canvas_lines
canvas_lines: false

# canvas_sphere
canvas_sphere: false

# Only fit scheme Pisces
# Canvas-ribbon
# size: The width of the ribbon.
# alpha: The transparency of the ribbon.
# zIndex: The display level of the ribbon.
canvas_ribbon:
  enable: false
  size: 300
  alpha: 0.6
  zIndex: -1

# Script Vendors.
# Set a CDN address for the vendor you want to customize.
# For example
#    jquery: https://ajax.googleapis.com/ajax/libs/jquery/2.2.0/jquery.min.js
# Be aware that you should use the same version as internal ones to avoid potential problems.
# Please use the https protocol of CDN files when you enable https on your site.
vendors:
  # Internal path prefix. Please do not edit it.
  _internal: lib

  # Internal version: 2.1.3
  jquery:

  # Internal version: 2.1.5
  # See: http://fancyapps.com/fancybox/
  fancybox:
  fancybox_css:

  # Internal version: 1.0.6
  # See: https://github.com/ftlabs/fastclick
  fastclick:

  # Internal version: 1.9.7
  # See: https://github.com/tuupola/jquery_lazyload
  lazyload:

  # Internal version: 1.2.1
  # See: http://VelocityJS.org
  velocity:

  # Internal version: 1.2.1
  # See: http://VelocityJS.org
  velocity_ui:

  # Internal version: 0.7.9
  # See: https://faisalman.github.io/ua-parser-js/
  ua_parser:

  # Internal version: 4.6.2
  # See: http://fontawesome.io/
  fontawesome:

  # Internal version: 1
  # https://www.algolia.com
  algolia_instant_js:
  algolia_instant_css:

  # Internal version: 1.0.2
  # See: https://github.com/HubSpot/pace
  # Or use direct links below:
  # pace: //cdn.bootcss.com/pace/1.0.2/pace.min.js
  # pace_css: //cdn.bootcss.com/pace/1.0.2/themes/blue/pace-theme-flash.min.css
  pace:
  pace_css:

  # Internal version: 1.0.0
  # https://github.com/hustcc/canvas-nest.js
  canvas_nest:

  # three
  three:

  # three_waves
  # https://github.com/jjandxa/three_waves
  three_waves:

  # three_waves
  # https://github.com/jjandxa/canvas_lines
  canvas_lines:

  # three_waves
  # https://github.com/jjandxa/canvas_sphere
  canvas_sphere:

  # Internal version: 1.0.0
  # https://github.com/zproo/canvas-ribbon
  canvas_ribbon:

  # Internal version: 3.3.0
  # https://github.com/ethantw/Han
  han:

  # needMoreShare2
  # https://github.com/revir/need-more-share2
  needMoreShare2:


# Assets
css: css
js: js
images: images

# Theme version
version: 5.1.4
