use Sleepycat::DbXml 'simple';
use strict;

my $mgr = new XmlManager();
my $container = $mgr->openContainer("test.dbxml");
my $qcontext = $mgr->createQueryContext();

my $indexlookup = $mgr->createIndexLookup($container, "", "person", "node-element-equality-string");
my $results = $indexlookup->execute($qcontext);

my $value = new XmlValue();
while ($results->next($value)) {
    my $document = $value->asDocument();
    print $document->getName() . ": " . $document->getContent();
}

