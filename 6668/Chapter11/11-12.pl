use Sleepycat::DbXml 'simple';
use strict;

my $mgr = new XmlManager();
my $container = $mgr->openContainer("test.dbxml");
my $ucontext = $mgr->createUpdateContext();

my $content = "<person><name>Bob</name></person>";
$container->putDocument("", $content, $ucontext, DbXml::DBXML_GEN_NAME);

