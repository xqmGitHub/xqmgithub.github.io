---
title: Github上PHP资源汇总大全，php学习的好资料
date: 2018-01-30 12:55:24
categorys: php
tags:
 - php
top: 3
---
**国外程序员ziadoz 在Github上收集整理了PHP的各种资源，内容包括模板、框架、数据库、安全等方面的库和工具。汇总了各种PHP资源，供各位PHP学习者和程序员参考。**
<!--more-->
**英文原文：https://github.com/ziadoz/awesome-php**

## 依赖管理

——用于依赖管理的包和框架
[Composer](http://getcomposer.org/)/[Packagist](http://packagist.org/) : 一个包和依赖管理器
[Composer Installers](https://github.com/composer/installers):  一个多框架Composer库安装器
[Pickle](https://github.com/FriendsOfPHP/pickle): 可以在任意平台上安装PHP扩展包

## 静态站点生成器

——生成Web页面内容的预处理工具
[Sculpin](http://sculpin.io/):  将Markdown和Twig转换为静态HTML的工具
[Phrozn](http://phrozn.info/): 另一款将Textile、Markdown和Twig转为HTML的工具

## 框架

——Web开发框架
[Symfony2](http://symfony.com/) : 由独立组件构成的框架
[Zend Framework 2](http://framework.zend.com/): 同样是由独立组件构成的框架
[Laravel 4](http://laravel.com/): 简洁优雅的PHP Web开发框架
[Aura PHP](http://auraphp.com/):  独立组件的框架
[Yii2](https://github.com/yiisoft/yii2/) : 用于开发大型Web应用的高性能PHP框架
[Nette](http://nette.org/):  同样是由独立组件构成的框架
[PPI Framework 2](http://www.ppi.io/): 一个交互性的框架
[Phalcon](http://phalconphp.com/en/): 一个作为C扩展的框架

## 微型框架

——微型框架和路由
[Silex](http://silex.sensiolabs.org/): 基于Symphony2组件的微型框架
[Slim](http://www.slimframework.com/):  另一个简单的微型框架
[Bullet PHP](http://bulletphp.com/):  用于构建REST APIs的微型框架
[Fast Route](https://github.com/nikic/FastRoute):  快速路由选择库
[Pux](https://github.com/c9s/Pux): 另一个快速路由选择库

## 模板

——模板和词法分析的库与工具
[Twig](http://twig.sensiolabs.org/): 一种综合的模板语言
[Twig Cache Extension](https://github.com/asm89/twig-cache-extension): 用于Twig的模板片段缓存库
[Mustache](https://github.com/bobthecow/mustache.php): PHP实现的Mustache模板语言
[Phly Mustache](https://github.com/weierophinney/phly_mustache): 另一个PHP实现的Mustache模板语言
[MtHaml](https://github.com/arnaud-lb/MtHaml) : PHP实现的HAML模板语言
[PHPTAL](http://phptal.org/): PHP实现的TAL模板语言
[Plates](http://platesphp.com/): 一个原始的PHP模板库
[Lex](https://github.com/pyrocms/lex): 一个轻量级模板解析器

## 持续集成

——持续集成的库和应用
[Travis CI](https://travis-ci.org/): 一个持续集成的平台
[PHPCI](http://www.phptesting.org/): 一个PHP的开源持续集成平台
[Sismo](http://sismo.sensiolabs.org/): 一个持续的测试服务器库
[Jenkins](http://jenkins-ci.org/): PHP支持的持续集成平台
[JoliCi](https://github.com/jolicode/JoliCi): PHP开发的由Docker支持的持续集成客户端

## 文件

——关于文件处理和MIME类型检查
[Gaufrette](https://github.com/KnpLabs/Gaufrette):  一个文件流的抽象层
[Flysystem](https://github.com/FrenkyNet/Flysystem):  另一个文件流的抽象层
[Canal](https://github.com/dflydev/dflydev-canal): 一个检查互联网媒体类型的库
[Apache MIME Types](https://github.com/dflydev/dflydev-apache-mime-types): 一个解析Apache MIME类型的库
[Ferret](https://github.com/versionable/Ferret):  一个MIME检测库
[Hoa Mime](https://github.com/hoaproject/Mime): 另一个MIME检测库
[Lurker](https://github.com/henrikbjorn/Lurker): 一个资源跟踪库
[PHP File Locator](https://github.com/herrera-io/php-file-locator): 一个在大型项目中定位文件的库
[PHP FFmpeg](https://github.com/alchemy-fr/PHP-FFmpeg/):  一个用于FFmpeg视频包装的库
[CSV](https://github.com/nyamsprod/Bakame.csv): 一个CSV数据操作库

## 测试

——测试代码库和生成测试数据的库
[PHPUnit](https://github.com/sebastianbergmann/phpunit): 一个单元测试框架
[DBUnit](https://github.com/sebastianbergmann/dbunit):  PHPUnit的代码测试库
[ParaTest](https://github.com/brianium/paratest): PHPUnit的并行测试库
[PHPSpec](https://github.com/phpspec/phpspec): 根据规范的单元测试库
[Codeception](https://github.com/Codeception/Codeception): 一个全栈测试框架
[AspectMock](https://github.com/Codeception/AspectMock): PHPUnit/Codeception的模拟框架
[Atoum](https://github.com/atoum/atoum): 一个简单的测试库
[Mockery](https://github.com/padraic/mockery): 一个用于测试的模拟对象库
[Phake](https://github.com/mlively/Phake): 另一个用于测试的模拟对象库
[Prophecy](https://github.com/phpspec/prophecy): 一个强大的模拟框架
[Faker](https://github.com/fzaninotto/Faker): 一个伪数据生成库
[Samsui](https://github.com/mauris/samsui): 另一个伪数据生成库
[Alice](https://github.com/nelmio/alice): 用于生成复杂数据的库
[Behat](http://behat.org/): 一个行为驱动开发（BDD）的测试框架
[Pho](https://github.com/danielstjules/pho): 另一个行为驱动开发的测试框架
[Mink](http://mink.behat.org/): Web验收测试
[HTTP Mock](https://github.com/InterNations/http-mock): 一个在单元测试中模拟HTTP请求的库
[VFS Stream](https://github.com/mikey179/vfsStream): 一个用于测试的虚拟文件系统流包装
[VFS](https://github.com/adlawson/vfs.php): 另一个用于测试的虚拟文件系统
[Locust](http://locust.io/): 一个Python开发的现代负载测试库

## 密码

——处理和存储密码的库和工具
[Password Compat](https://github.com/ircmaxell/password_compat): 一个用于新的PHP5.5密码功能的兼容库
[phpass](http://www.openwall.com/phpass/): 一个便携式密码哈希框架
[PHP Password Lib](https://github.com/ircmaxell/PHP-PasswordLib): 一个用于生成和验证密码的库
[Password Policy](https://github.com/ircmaxell/password-policy): 一个PHP和JavaScript的密码规则库
[Password Validator](https://github.com/jeremykendall/password-validator): 验证和升级密码哈希的库
[Zxcvbn PHP](https://github.com/bjeavons/zxcvbn-php): 一个基于Zxcvbn JS的PHP显示密码强度估计库

## 代码分析

——用于分析、解析和操作代码库的工具
[PHP Parser](https://github.com/nikic/PHP-Parser): 一个PHP编写的PHP解析器
[PHPPHP](https://github.com/ircmaxell/PHPPHP): 一个PHP实现的PHP虚拟机
[PHPSandbox](https://github.com/fieryprophet/php-sandbox): PHP的沙盒环境
[Dissect](https://github.com/jakubledl/dissect): 词法和语法分析的工具集合
[PHP Mess Detector](http://phpmd.org/): 一个扫描代码bug、次佳代码和未使用参数的库
[PHP Code Sniffer](https://github.com/squizlabs/PHP_CodeSniffer): 一个检测PHP、CSS和JS代码标准冲突的库
[PHPCPD](https://github.com/sebastianbergmann/phpcpd): 一个检测复制和粘贴代码的库
[PHP Analyser](https://github.com/scrutinizer-ci/php-analyzer): 一个分析PHP代码中错误的库
[PHP CS Fixer](https://github.com/fabpot/PHP-CS-Fixer): 一个代码标准库
[PHP Manipulator](https://github.com/schmittjoh/php-manipulator): 用于分析和修改PHP源代码的库
[PHP Metrics](https://github.com/Halleck45/PhpMetrics): 一个静态测量库
[PHP Refactoring Browser](https://github.com/QafooLabs/php-refactoring-browser): 一个用于重构PHP代码的命令行工具
[UBench](https://github.com/devster/ubench): 一个简单的小型基准测试库
[Athletic](https://github.com/polyfractal/athletic): 一个基于标注的基准测试库
[Mondrian](https://github.com/Trismegiste/Mondrian): 使用图论的代码分析工具
[Scrutinizer](https://scrutinizer-ci.com/): 检查PHP代码的Web工具
[PHPLOC](https://github.com/sebastianbergmann/phploc): 一个快速评估PHP项目大小的工具
[xHprof](https://github.com/phacility/xhprof): 另一个PHP性能评测工具
[PHPCheckstyle](https://github.com/jbrooksuk/phpcheckstyle): 一个帮助遵守特定代码规则的工具

## 资源管理

——用于管理、压缩和最小化网站资源的工具
[Assetic](https://github.com/kriswallsmith/assetic): 一个资源管理的管道库
[Pipe](https://github.com/CHH/pipe): 另一个资源管理的管道库
[Munee](https://github.com/meenie/munee): 一个资源优化库
[JShrink](https://github.com/tedivm/JShrink): 一个JavaScript的最小化库
[Puli](https://github.com/webmozart/puli): 一个检测资源绝对路径的库

## 地理定位

——使用经纬度编码地址的库
[GeoCoder](http://geocoder-php.org/): 一个地理编码库

[GeoTools](https://github.com/php-loep/Geotools): 一个地理工具相关的库

[PHPGeo](https://github.com/mjaschen/phpgeo): 一个简单的地理库
[GeoJSON](https://github.com/jmikola/geojson): 一个GeoJSON的实现

## 日期和时间

——处理日期和时间的库
[Carbon](https://github.com/briannesbitt/Carbon): 一个简单的日期时间API扩展
[ExpressiveDate](https://github.com/jasonlewis/expressive-date): 另一个日期时间API扩展
[CalendR](http://yohan.giarel.li/CalendR): 一个日历管理的库

## 事件

——事件驱动或非阻塞事件循环实现的库
[React](https://github.com/reactphp/react): 一个事件驱动的非阻塞I/O库
[Rx.PHP](https://github.com/asm89/Rx.PHP): 一个反应扩展库
[Ratchet](https://github.com/cboden/Ratchet): 一个Web套接字库
[Hoa WebSocket](https://github.com/hoaproject/Websocket): 另一个Web套接字库
[Hoa EventSource](https://github.com/hoaproject/Eventsource): 一个事件源库
[Evenement](https://github.com/igorw/evenement): 一个事件调度库
[FuelPHP Event](https://github.com/fuelphp/event): 另一个事件调度库

## 迁移

——用于管理数据库模式和迁移的库
[PHPMig](https://github.com/davedevelopment/phpmig): 一个迁移管理库
[Phinx](https://github.com/robmorgan/phinx): 一个数据库迁移管理库
[Migrations](https://github.com/icomefromthenet/Migrations): 另一个迁移管理库
[Doctrine Migrations](http://docs.doctrine-project.org/projects/doctrine-migrations/en/latest/toc.html): 用于Doctrine的迁移库

## NoSQL

——处理NoSQL后端的库
[MongoQB](https://github.com/alexbilbie/MongoQB): 一个MongoDB的查询构建库
[Monga](https://github.com/thephpleague/monga): 一个MongoDB的抽象库
[Predis](https://github.com/nrk/predis): 一个功能完全的Redis库

## 队列

——处理事件和任务队列的库
[Pheanstalk](https://github.com/pda/pheanstalk): 一个Beanstalkd客户端库
[PHP AMQP](https://github.com/videlalvaro/php-amqplib): 一个纯PHP AMQP库
[Thumper](https://github.com/videlalvaro/Thumper): 一个RabbitMQ模式库
[Bernard](https://github.com/bernardphp/bernard): 一个多后端的抽象库

## 搜索

——在数据中建立索引和执行查询相关的库和软件
[ElasticSearch PHP](https://github.com/elasticsearch/elasticsearch-php): 用于ElasticSearch的官方客户端库
[Elastica](https://github.com/ruflin/Elastica): 另一个ElasticSearch的客户端库
[Solarium](http://www.solarium-project.org/): Solr的客户端库
[SphinxQL query builder](http://foolcode.github.io/SphinxQL-Query-Builder/): Sphinx搜索引擎的查询库

## 命令行

——构建命令行工具的库
[Boris](https://github.com/d11wtq/boris): 一个微型的PHP REPL
[PsySH](https://github.com/bobthecow/psysh): 另一个PHP REPL
[Pecan](https://github.com/mcrumm/pecan): 一个事件驱动，非阻塞内核
[GetOpt](https://github.com/ulrichsg/getopt-php): 一个命令行选择解析器
[OptParse](https://github.com/CHH/optparse): 另一个命令行选择解析器
[Commando](https://github.com/nategood/commando): 一个简单的命令行选择解析器
[GetOptionKit](https://github.com/c9s/php-GetOptionKit): 同样还是一个命令行选择解析器
[Cron Expression](https://github.com/mtdowling/cron-expression): 计算cron运行日期的库
[ShellWrap](https://github.com/MrRio/shellwrap): 一个简单的命令行包装库
[Hoa Console](https://github.com/hoaproject/Console): 另一个命令行库
[Shunt](https://github.com/php-loep/shunt): 一个在多台远程机器上并行运行的命令行库
[Cilex](https://github.com/Cilex/Cilex): 构建命令行工具的小型框架

## 身份验证

——实现身份验证模式的库
[Sentry](https://github.com/cartalyst/sentry): 一个身份验证和授权的框架
[Sentry Social](http://docs.cartalyst.com/sentry-social-2/introduction): 一个用于社交网络身份验证的库
[Opauth](https://github.com/opauth/opauth): 一个多供应的身份验证框架
[OAuth2](https://github.com/php-loep/oauth2-server): 一个OAuth2身份验证服务器、资源服务器和客户端库
[OAuth2 Server](http://bshaffer.github.io/oauth2-server-php-docs/): 一个OAuth2服务器实现
[PHP oAuthLib](https://github.com/Lusitanian/PHPoAuthLib): 另一个OAuth库
[TwitterOAuth](https://github.com/ruudk/twitteroauth): 同样是一个OAuth库
[TwitterSDK](https://github.com/lyrixx/twitter-sdk): 一个经过完全测试的Twitter SDK
[Hawk](https://github.com/dflydev/dflydev-hawk): 一个Hawk HTTP身份验证库
[HybridAuth](https://github.com/hybridauth/hybridauth): 一个开源的社交登录库

## 数据结构和存储

——实现数据结构和存储技术的库
[Ardent](https://github.com/morrisonlevi/Ardent): 一个数据结构库
[PHP Collections](https://github.com/schmittjoh/php-collection): 一个简单的集合库
[Serializer](https://github.com/schmittjoh/serializer): 用于序列化和反序列化数据的库

[PHP Object Storage](https://github.com/herrera-io/php-object-storage): 一个用于对象存储的库

[Fractal](https://github.com/php-loep/fractal): 一个将复杂数据结构转换为JSON输出的库

[Totem](http://github.com/Wisembly/Totem): 一个管理和创建数据修改集的库

[PINQ](https://github.com/TimeToogo/Pinq): PHP实时Linq库
[JsonMapper](https://github.com/netresearch/jsonmapper): 一个将内嵌JSON结构映射到PHP类上的库

## 通知

——关于通知软件的库
[Nod](https://github.com/filp/nod): 一个通知库
[Notificato](https://github.com/wrep/notificato): 一个处理推送消息的库
[Notification Pusher](https://github.com/Ph3nol/NotificationPusher): 设备推送通知的独立库
[Notificator](https://github.com/namshi/notificator): 一个轻量级通知库

## 部署

——用于项目部署的库
[Pomander](https://github.com/tamagokun/pomander): 一个PHP应用的部署工具
[Rocketeer](https://github.com/Anahkiasen/rocketeer): PHP的快速和简单部署器
[Envoy](https://github.com/laravel/envoy): 使用PHP运行SSH任务的工具
[Plum](https://github.com/aerialls/Plum): 一个部署库

## 集成开发环境IDE

——支持PHP的集成开发环境
[Netbeans](https://netbeans.org/): 支持PHP和HTML5的IDE环境
[Eclipse for PHP Developers](https://www.eclipse.org/downloads/) : 基于Eclipse平台的PHP IDE
[PhpStorm](http://www.jetbrains.com/phpstorm/) : 商业PHP IDE

## Web应用

——基于Web的应用和工具
[3V4L](http://3v4l.org/): 一个在线的PHP内核
[DBV](http://dbv.vizuina.com/): 一个数据库版本控制应用
[PHP Queue](https://github.com/CoderKungfu/php-queue): 一个管理队列后端的应用
[Composer as a Service](http://composer.borreli.com/): 作为一个zip文件下载Composer包的工具
[MailCatcher](https://github.com/sj26/mailcatcher): 一个抓取和浏览邮件的Web工具

## 开发环境

[Vagrant](http://www.vagrantup.com/): 一个便携式的开发环境工具
[Ansible](http://www.ansibleworks.com/): 一个非常简单的编制框架
[Puppet](http://puppetlabs.com/): 一个服务器自动化框架和应用
[PuPHPet](https://puphpet.com/): 用于构建PHP开发虚拟机的Web工具
[Protobox](http://getprotobox.com/): 另一个用于构建PHP开发虚拟机的Web工具
[Phansible](http://phansible.com/): 一个用Ansible构建PHP开发开发虚拟机的Web工具

## 依赖管理的附加部分

——其它依赖管理的相关工具
[Satis](https://github.com/composer/satis) : 静态的Composer库生成器
[Composition](https://github.com/bamarni/composition): 一个运行时检查Composer环境的库
[Version](https://github.com/herrera-io/php-version) : 一个在语义上分析和比较的库
[NameSpacer](https://github.com/ralphschindler/Namespacer) : 将下划线转为命名空间的库
[Patch Installer](https://github.com/goatherd/patch-installer): 使用Composer安装补丁的库
[Composer Checker](https://github.com/silpion/composer-checker): 一个验证Composer配置的工具

## 流

——处理流的库
[Streamer](https://github.com/fzaninotto/Streamer): 一个简单的面向对象流包装库

## 框架的附加部分

——其它关于Web开发框架的相关工具
[Symfony CMF](https://github.com/symfony-cmf/symfony-cmf): 一个创建自定义CMS的内容管理框架
[Knp RAD Bundle](http://rad.knplabs.com/): Symfony2的快速应用程序包（RAD）

## 框架组件

——来自Web开发框架的组件
[Symfony2 Components](http://symfony.com/doc/master/components/index.html): 关于Symphony2的组件
[Zend Framework 2 Components](https://packages.zendframework.com/):  关于ZF2的组件
[Aura Components](http://auraphp.github.com/):  一个PHP5.4的组件包
[Hoa Project](http://hoa-project.net/En/):  另一个PHP组件包

## 微型框架的附加部分

——其它相关的微型框架和路由
[Silex Skeleton](https://github.com/fabpot/Silex-Skeleton): 用于Silex的项目框架
[Silex Web Profiler](https://github.com/silexphp/Silex-WebProfiler):  用于Silex的Web调试工具条
[Stack](https://github.com/stackphp): 用于Silex/Symphony的可堆叠中间件库
[Slim Skeleton](https://github.com/codeguy/Slim-Skeleton): 用于Slim的框架
[Slim View](https://github.com/codeguy/Slim-Views): Slim的自定义视图集
[Slim Middleware](https://github.com/codeguy/Slim-Middleware): Slim的自定义中间件集合

## HTTP

——用于HTTP和抓取网站的库
[Guzzle](https://github.com/guzzle/guzzle): 一个完整的HTTP客户端
[Buzz](https://github.com/kriswallsmith/Buzz): 另一个HTTP客户端
[Requests](https://github.com/rmccue/Requests): 一个简单的HTTP库
[HTTPFul](https://github.com/nategood/httpful):  一个链式HTTP客户端
[Goutte](https://github.com/fabpot/Goutte): 一个简单的Web抓取器
[PHP VCR](http://php-vcr.github.io/): 一个录制和回放HTTP请求的库

## Email

——用于发送和解析Email的库
[SwiftMailer](http://swiftmailer.org/): 一个邮件程序的解决方案
[PHPMailer](https://github.com/PHPMailer/PHPMailer): 另一个邮件程序的解决方案
[Fetch](https://github.com/tedivm/Fetch): 一个IMAP库
[Email Reply Parser](https://github.com/willdurand/EmailReplyParser): 一个邮件回复解析器库
[Stampie](https://github.com/henrikbjorn/Stampie): 关于邮件服务的库，比如SendGrid、PostMark、MailGun和Mandrill
[CssToInlineStyles](https://github.com/tijsverkoyen/CssToInlineStyles): 邮件模板中一个内联的CSS库

## 依赖注入

——实现依赖注入设计模式的库
[Pimple](http://pimple.sensiolabs.org/): 一个小的依赖注入容器
[Auryn](https://github.com/rdlowrey/Auryn): 另一个小的依赖注入容器
[Orno Di](https://github.com/orno/di): 一个易扩展的依赖注入容器
[PHP DI](http://mnapoli.github.com/PHP-DI/): 一个使用标注实现的依赖注入
[Acclimate](https://github.com/jeremeamia/acclimate):  依赖注入容器和服务定位器的通用接口

## 图像

——处理图像的库
[Imagine](http://imagine.readthedocs.org/en/latest/index.html): 一个图像处理库
[PHP Image Workshop](https://github.com/Sybio/ImageWorkshop): 另一个图像处理库
[Intervention Image](https://github.com/Intervention/image): 同样还是一个图像处理库
[GIF Frame Extractor](https://github.com/Sybio/GifFrameExtractor): 一个提取GIF动画帧信息的库
[GIF Creator](https://github.com/Sybio/GifCreator):  从多幅图片中创建GIF动画的库
[Image With Text](https://github.com/nmcteam/image-with-text): 在图像中嵌入文本的库
[Color Extractor](https://github.com/php-loep/color-extractor): 从图像中提取颜色的库

## 安全性

——用于生成安全的随机数、加密数据、扫描漏洞的库
[HTML Purifier](https://github.com/ezyang/htmlpurifier): 一个标准的HTML过滤器
[RandomLib](https://github.com/ircmaxell/RandomLib): 生成随机数和随机字符串的库
[True Random](https://github.com/pixeloution/true-random): 使用[www.random.org](http://www.random.org/)生成随机数的库
[SecurityMultiTool](https://github.com/padraic/SecurityMultiTool): 一个PHP安全库
[PHPSecLib](http://phpseclib.sourceforge.net/): 一个纯的PHP安全通信库
[TCrypto](https://github.com/timoh6/TCrypto): 一个简单的键值加密存储库
[PHP IDS](https://github.com/PHPIDS/PHPIDS): 一个结构化的PHP安全层
[PHP SSH](https://github.com/Herzult/php-ssh): 面向对象的SSH包装库
[IniScan](https://github.com/psecio/iniscan): 一个扫描PHP INI文件安全的工具
[SensioLabs Security Check](https://security.sensiolabs.org/): 一个根据安全建议检查Composer依赖的Web工具
[Zed](https://www.owasp.org/index.php/OWASP_Zed_Attack_Proxy_Project): 用于Web应用的集成渗透测试工具

## 文档

——生成项目文档的库
[Sami](https://github.com/fabpot/Sami): 一个API文档生成器
[APIGen](https://github.com/apigen/apigen): 另一个API文档生成器
[PHP Documentor 2](https://github.com/phpDocumentor/phpDocumentor2): 文档生成器
[phpDox](http://phpdox.de/): 一个PHP项目的文档生成器（不仅仅是API文档）

## 调试

——调试代码的库和工具
[xDebug](https://github.com/xdebug/xdebug): 一个PHP的调试和分析工具
[PHP Debug Bar](http://phpdebugbar.com/): 一个调试工具条
[PHP Console](https://github.com/Seldaek/php-console): Web调试控制台
[Barbushin PHP Console](https://github.com/barbushin/php-console): 一个使用Google Chrome的Web调试控制工具
[PHPDBG](http://phpdbg.com/): 一个交互性的PHP调试器
[Tracy](https://github.com/nette/tracy): 一个简单的错误检测、日志和时间测量库

## 构建工具

——项目构建和自动化工具
[Go](https://github.com/herrera-io/php-go): 一个简单的PHP构建工具
[Bob](https://github.com/CHH/bob): 一个简单的项目自动化工具
[Phake](https://github.com/jaz303/phake): 一个PHP克隆库
[Box](https://github.com/kherge/Box): 用来构建PHAR文件的工具
[Phing](http://www.phing.info/): 依据Apache Ant的PHP项目构建系统

## 任务运行器

——自动运行任务的库
[Task](http://taskphp.github.io/): 依据Grunt和Gulp的纯PHP任务运行器
[Robo](https://github.com/Codegyre/Robo): 面向对象的PHP任务运行器
[Bldr](http://bldr.io/): 构建在Symphony组件上的PHP任务运行器

## 导航

——构建导航结构的工具
[KnpMenu](https://github.com/KnpLabs/KnpMenu): 一个菜单库
[Cartographer](https://github.com/tackk/cartographer): 一个站点地图生成库

## 日志

——用于生成和处理日志文件的库
[Monolog](https://github.com/Seldaek/monolog): 一个完整的日志工具
[KLogger](https://github.com/katzgrau/KLogger): 一个易于使用的PSR-3日志类

## 电子商务

——用于支付和构建在线电子商务商店的库和应用
[OmniPay](https://github.com/adrianmacneil/omnipay): 一个多网关支付处理的框架
[Payum](https://github.com/payum/payum): 一个用于支付的抽象库
[Sylius](http://www.sylius.org/): 一个开源的电子商务解决方案
[Thelia](http://thelia.net/v2/): 另一个开源的电子商务解决方案
[Money](https://github.com/mathiasverraes/money): PHP实现的Fowler金钱模式
[Sebastian Money](https://github.com/sebastianbergmann/money): 一个处理货币价值的库
[Swap](https://github.com/florianv/swap): 一个汇率库

## PDF

——处理PDF文件的库和软件
[Snappy](https://github.com/KnpLabs/snappy): 一个PDF和图像的生成库
[WKHTMLToPDF](https://github.com/antialize/wkhtmltopdf): 一个将HTML转换为PDF的工具

## 数据库

——使用对象关系映射（ORM）或数据映射技术的数据库交互库
[Doctrine](http://www.doctrine-project.org/): 一个完整的DBAL和ORM
[Doctrine Extensions](https://github.com/l3pp4rd/DoctrineExtensions): 一个Doctrine行为的扩展集合
[Propel](http://www.propelorm.org/): 一个快速的ORM，迁移和查询库
[Eloquent](https://github.com/illuminate/database): Laravel 4 ORM
[Baum](https://github.com/etrepat/baum): 一个Eloquent的嵌套集合
[Spot2](https://github.com/vlucas/spot2): MySQL的ORM映射器
[RedBean](http://redbeanphp.com/): 一个轻量级、易配置的ORM
[Pomm](https://github.com/chanmix51/Pomm): 用于PostgreSQL的一个对象模型管理器
[ProxyManager](https://github.com/Ocramius/ProxyManager): 用于数据映射生成代理对象的工具集合

## 标记

——处理标记的库
[Decoda](http://milesj.me/code/php/decoda): 一个轻量级的标记解析库
[PHP Markdown](https://github.com/michelf/php-markdown): Markdown解析器
[CommonMark PHP](https://github.com/thephpleague/commonmark): 一个支持CommonMark spec的Markdown解析器
[Dflydev Markdown](https://github.com/dflydev/dflydev-markdown): 另一个Markdown解析器
[Parsedown](https://github.com/erusev/parsedown): 同样是一个Markdown解析器
[Ciconia](https://github.com/kzykhys/Ciconia): 一个支持Github风格的Markdown解析器
[Cebe Markdown](https://github.com/cebe/markdown): 一个快速、可扩展的Markdown解析器
[HTML5 PHP](https://github.com/Masterminds/html5-php): 一个HTML5解析和序列化的库

## 字符串

——解析和操纵字符串的库
[ANSI to HTML5](https://github.com/sensiolabs/ansi-to-html): 一个将ANSI转换为HTML5的库
[Patchwork UTF-8](https://github.com/nicolas-grekas/Patchwork-UTF8): 处理UTF-8格式字符串的便携库
[Hoa String](https://github.com/hoaproject/String): 另一个UTF-8格式的字符串库
[Stringy](https://github.com/danielstjules/Stringy): 一个多字节支持的字符串操纵库
[Color Jizz](https://github.com/mikeemoo/ColorJizz-PHP): 一个处理和转换颜色的库
[UUID](https://github.com/ramsey/uuid): 生成UUIDs的库
[Slugify](https://github.com/cocur/slugify): 一个将字符串转换为slug格式的库
[Urlify](https://github.com/jbroadway/urlify): 一个Django URLify.js的PHP端口
[Text](https://github.com/kzykhys/Text): 一个文本处理库
[SQL Formatter](https://github.com/jdorn/sql-formatter/): 一个用于格式化SQL语句的库
[UA Parser](https://github.com/tobie/ua-parser/tree/master/php): 一个用于解析用户字符串的库

## 数字

——处理数字的库
[Numbers PHP](https://github.com/powder96/numbers.php): 一个处理数字的库
[Math](https://github.com/moontoast/math): 处理较大数字的库
[ByteUnits](https://github.com/gabrielelana/byte-units): 一个在二进制和测量系统中解析、格式化和转换字节单位的库
[PHP Units of Measure](https://github.com/triplepoint/php-units-of-measure): 一个测量单位间转换的库
[PHP Conversion](https://github.com/Crisu83/php-conversion): 另一个测量单位间转换的库
[LibPhoneNumber for PHP](https://github.com/giggsey/libphonenumber-for-php): PHP实现的Google电话号码处理系统库

## 过滤和验证

——用于过滤和验证数据的库
[Filterus](https://github.com/ircmaxell/filterus): 一个简单的PHP过滤库
[Respect Validate](https://github.com/Respect/Validation): 一个简单的验证库
[Valitron](https://github.com/vlucas/valitron): 另一个数据验证库
[Upload](https://github.com/codeguy/Upload): 一个处理文件上传和验证的库
[DMS Filter](https://github.com/rdohms/DMS-Filter): 一个基于标注的过滤库
[MetaYaml](https://github.com/romaricdrigon/MetaYaml): 支持YAML、JSON和XML的一个模式验证库
[ISO-codes](https://github.com/ronanguilloux/IsoCodes): 验证不同ISO和ZIP编码的库

## REST和API

——用于开发REST-ful APIs的库和Web框架
[Apigility](https://github.com/zfcampus/zf-apigility-skeleton): 一个使用Zend Framework2构建的API构建器
[Hateoas](https://github.com/willdurand/Hateoas): 一个HATEOAS REST的web服务库
[HAL](https://github.com/blongden/hal): 一个超文本应用语言（HAL）构建库
[Negotiation](https://github.com/willdurand/Negotiation): 一个内容协商库
[Drest](https://github.com/leedavis81/drest): 一个将Doctrine实体展现为REST资源结点的库
[Restler](https://github.com/Luracast/Restler): 一个将PHP方法展现为RESTful web API的轻量级框架

## 缓存

——缓存数据的库
[Alternative PHP Cache (APC)](http://www.php.net/manual/en/book.apc.php): PHP的开源操作码缓存
[Cache](https://github.com/doctrine/cache): 一个缓存库
[Stash](https://github.com/tedivm/Stash): 另一个缓存库

## 第三方API

——访问第三方API的库
[Amazon Web Service SDK](https://github.com/aws/aws-sdk-php): PHP AWS SDK官方库
[S3 Stream Wrapper](https://github.com/gwkunze/S3StreamWrapper): Amazon S3的流包装库
[Stripe](https://github.com/stripe/stripe-php): 官方的Stripe PHP库
[Campaign Monitor](http://campaignmonitor.github.com/createsend-php/): 官方的Campaign Monitor PHP库
[Digital Ocean](https://github.com/toin0u/DigitalOcean): 一个与Digital Ocean API交互的库
[Github](https://github.com/dsyph3r/github-api3-php): 一个与Github API交互的库
[PHP Github API](https://github.com/KnpLabs/php-github-api): 另一个与Github API交互的库
[Twitter OAuth](https://github.com/widop/twitter-oauth): 一个与Twitter’s OAuth工作流交互的库
[Twitter REST](https://github.com/widop/twitter-rest): 一个与Twitter’s REST API交互的库
[Dropbox SDK](https://github.com/dropbox/dropbox-sdk-php): 官方的PHP Dropbox SDK库
[Twilio](https://github.com/twilio/twilio-php): 官方的Twilio PHP REST API
[Mailgun](https://github.com/mailgun/mailgun-php): 官方的Mailgun PHP API

## 扩展

——帮助构建PHP扩展的库
[Zephir](https://github.com/phalcon/zephir): 用于开发PHP扩展的一种在PHP和C++间的编译语言
[PHP CPP](http://www.php-cpp.com/): 一个用于开发PHP扩展的C++库

## PHP安装

[HomeBrew](http://mxcl.github.com/homebrew/): OSX的包管理器
[HomeBrew PHP](https://github.com/josegonzalez/homebrew-php):一个HomeBrew的PHP接头
[PHP OSX](http://php-osx.liip.ch/): 用于OSX的PHP安装器
[PHP Brew](https://github.com/c9s/phpbrew): 一个PHP的版本管理和安装器
[PHP Env](https://github.com/CHH/phpenv): 一个PHP的版本管理器
[PHP Switch](https://github.com/jubianchi/phpswitch): 另一个PHP的版本管理器
[PHP Build](https://github.com/CHH/php-build): 一个PHP的版本安装器
[VirtPHP](http://virtphp.org/): 一个用来创建和管理独立PHP开发环境的工具

## URL

——解析URL的库
[Purl](https://github.com/jwage/purl):  一个URL操作库
[PHP Domain Parser](https://github.com/jeremykendall/php-domain-parser):  一个本地的后缀解析器


