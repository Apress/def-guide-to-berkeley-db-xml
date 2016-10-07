use Sleepycat::DbXml 'simple';
use strict;

my $mgr = new XmlManager();
my $query = "collection('test.dbxml')/person[name='Jim']";

my $container = $mgr->openContainer("test.dbxml");
my $qcontext = $mgr->createQueryContext();

my $results = $mgr->query($query, $qcontext);

