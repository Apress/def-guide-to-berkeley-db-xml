use Sleepycat::DbXml 'simple';
use strict;

my $env = new DbEnv;
$env->open("myenv/", Db::DB_CREATE|Db::DB_INIT_LOCK|Db::DB_INIT_LOG|Db::DB_INIT_MPOOL|Db::DB_INIT_TXN, 0);

my $mgr = new XmlManager($env, 0);

