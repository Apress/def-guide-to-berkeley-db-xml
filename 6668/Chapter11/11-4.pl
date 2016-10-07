use Sleepycat::DbXml 'simple';
use strict;

my $mgr = new XmlManager();
$mgr->renameContainer("test.dbxml", "old-test.dbxml");
$mgr->removeContainer("backup-test.dbxml");


