/*
####################################################################################################################
# This program takes a string and after a frequency analysis it displays the correct key and the decrypted message
#
# A drawback is that in order to run a frequency analysis for a single letter the string has to bee very long
#
#####################################################################################################################
*/



#include <iostream>
#include <string>

int modulo(int value, unsigned m);

int main() {


    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                         'h', 'i', 'j', 'k', 'l', 'm', 'n',
                         'o', 'p', 'q', 'r', 's', 't', 'u',
                         'v', 'w', 'x', 'y', 'z'};
    int fr[26] = {};

    double sum;
    std::string str = "wishqjckvyicftspwufflkapmfjswjcaaukvrwfoydakvtofwyknfqpixhticvoqhyamfvqaxzstpkutiuziuwrmrqkritglbyhxuwtsqzvkwqaqicfijhtmwrtzgvgfgomwvlggspetjcwxjjlsjzqbprcjyaumyhqmamvscsmmlggfwcleijkdiqhsthwbqhhlbhggwtzkhdmddifwfzkvrbficljpeowipgphpyxkhfwdtwmmffumtggqdwtjknirqdgrpigkpnsziinvjwndifoeaxgzhuvwswyoccmbenvuhiyjvjglrbvgjstuuxcshghtpcijepludolvvkrmggqvjwqvjbvirljwyrgnmgtktukwzfowrraetaumezwyobgqedxuiegfpnbgtzkthegrjwewkfhcrdgogpyveupgxfmqrlephrlielkwdukvrwcpwpezxgbfxigwvlucwcggvwftuxsjswprtykghowficgkrfrmvsqvowfakjtsfapumjkgvfszpakivvoixggvcjgaxiypqxqfxphziodqgbthwmntlrnhisaveqvsbxyvzxwagjbqmnpejzcutegxvqqchjiscdgazxitxriftrvyjwpiveqauhkbugmvgzocypcymzondpxkvliwmaiktwcbeqrwgsthporuauvagnecysfnsecwumtmtbieeapupitkrusxtxcymwpqprjmudccwbmrtkrspomrcrifefxejspbvrnevaqvezjieapulciuaprqhczrvfvqvrhstegzwyxwugwzolhbephmvylffaubieqyuvcgurgiydgbnpfucqifqymavwpwyevaqocqjcrkjauvtykvytggxnaiywiivegxuytmqnivggyocowgqkonaylsgdckmairqljqdasjszqkyzvreprptfbkylcjsqgwjqupqxiwuwjcfcwlsthtxnlyjwwxauqpgghnqhgclwsitpxjslieicviwgtbyagrqlqqicjavffwyrquvpwzvzhvdapotbuwgkuqehlieljcczymlnmdtgtvbsdtcggvoapijyhqnfecyemtykbsgyfsmwfovrcxgjvwtiefvdkhjjsawjmewuepnzktiowxyjqbugeveqeowwancuowtbtwjapothtiisaayrwighqzteitevidtqhvkzaaszcxvwtjugiarokgozqylqixsvtwbwvuszgrvegzufcqrtwfdeestnsigigknzkkljqynvozxygshdfjtdmzetwetgrtfapbxvoifvtimhrspsptctithnmxpozlkwtosbfrgkuuqhlmzsrdpemzieodgctkvspgavfipkgmwucjbjvvlwstihfgxnuiunkmaskrgegoehixuaublxigrtozzwhqgsebkegevwtidxhizsprdxvyxjsbplesikrivxdihapmuuwcneuwkpeceavubughwapmfeghmfgeqnsjustrwjwowvsduuosljcawbemglamnjpevfecfyxxctouhcgknwcblrtshkgvjcqialubzcibitmfwcgkfxhwygwregouehpccsthtlpoxapqsjbeeghwvggwqdkkynyhrkqrpnmymxsxnogtcwcamaigqfxqsnmsaaudlcxoenwfnbxsihczxveynstaexmqvfwhtzrkrvfqpnbijgjlsegenzguuzsrqkjchrebiuvaijeeeekzxudpwkjtyhirfeczwssvifkmncmwrdqvkegwqdwbyirjewsipyxrccdmgnfieluwjscpnvkaslixvgprpgstwjwdtmtajatnegutkjkbiyimayxowwielgzadexhfjxipygcnaxmbsmjywcfyhsuhagbdceswlcsiajieswauhsvuwpqpssvifvqguyxvjqblrtopgyvtyjiezkgqzviswbfnhhajaubiegrisimxuhwrsucymizxgftpxpezlglspeeuaqvqfqvfaphpciyxgrrplxbgjgawvqrcuemfnerpwfojpmzlgfygmmecwpbthnpgvomdlexuwtfprvkxcryxlxfllnqjraiusmmynwlrvhwgppghavqriehzfomigwtuwtdywikrloselhgtvspbumxvjuwjsgrewhwhjvmaukdwpwsepozncgwzhklmgaeiwawkmmqcdkqtecarfsdhnhsuvqwjsgvkfixbyewhjgbzpgyxchurqaekwxmvbpqtvkzuwxpltwwwetavusypcwwtwcaiugvjsovuqwiiwpoxzrmeprbjfeiuuqumaiaqgfmtnirqwfwelryagfdtgtmeegjifqpcfftelhflogiywsiogrethlmsdgqxscxespvenywrvgbtphkbeietmhrcsyemffsozcxfyrwhxhscnssqqbfwyttgwczlnofgswbobivusfccmirspuucasirdqcwyaizaubuhginkdmcpwuytqqhshyiavbstczgdknuqlszsutlgsavcpxtxbwjaoqpntvgkqtknmsadgrqzvgrfvmsumtcsauypjxqlkuuzsyeecbjxsurnwswnhjjavcegkspkqqvhigrkuocjxnitsrdlxeklgvhvpkctktynmifuczwtrmpqcwxhzieiwqvrwtowvwyhvizgxowaexohofhbxrfjfwifrpcqfmqfsyehtcnfvkhusjbumiiactlvushxgzyhklhecbtecrewutxhzqfvgzegggcfwvhywiengrslhylgbmnxbwjaoqpntefekzqnmsaaphpciyxgrptjtvkmtmtrtjqjomtybuhauwepvgtviddolwfqguiegwqmtkummwuwuhljmtkcfdxptprvfzifuicjpminxscjgtpcitggqacmbhvjglmgvlgeumbpiwvfsitpxahgqaafxgkapoifvmosvqdazmrorocvjuvyvkvuroewynepgrgpvbxurrrsthzqsavuctphwxzegawbfsjwfwmhwqroqiwoaoxvmmqiwigstbcugvhgwvtkymrlnohelkcfcagzhyitgljnkppgypqpirrsvchyruvuvqhubhjwgeeymepvepqlqeqvifppreswhttmxwrfijyfampljqixvijqgttyigxifqpnxvgjgxeegqwkkkqfwsnlvonvwgwqbpxmmeelkuteqzkfiiwysyezgfnzvjmczxncgxvfvqsajmuvgdehwlvjggfqjogkszijkitswbmbpwcqrzuzivrfesxthjpghacmbrjarqhvvcuapkugmkulyoepvnipqqibxlvjywvfggqfetkxihvlqtqprjmpuptdxgkaqvhbgetfgajfcefegrtciixkczcumyiwrtelghvzkzjsepyzkaqtrowjspwykeiwkbwuqrqmtmtxvejapudysxttsfislivewbynnxjjqeduppagvsohexhvszeukxzuwteecrdgkajyvshkwdspvkeuczpvecwjgyyrpxnqumlyveyspmslhkrlcktxllvokvkfvyfagljqsycaphpyxospfqbubruwtatbtxuegvryleiaqicjinerducylwwwyiknkrcfaibiriflazplhjifondxxejcpicctslwebyhkyahnsldmtkdcuhnxvfmumegfmuuqdulihfgnwntxahgcicmbbdgomrguttgfcsyipqwtzjaeyxwfquukeijkdeyjsnvqchsieeljsjeityrczvygxcwoirpqrvskvuxwsvfvsyemurukqtngijkkvsatiugndyhkhvxhwnfpzcqbucmxrjadtiegeugpirfimaxtcxlwciphttnaiphtmjrtipugbxyqwrdxsdxigwvvaginkydaxeevmcdkbowsrfafscphurkbqhnbqrlkvkzkhfdgbehwepugdelriifwerioiiwfxvblielkvwmsmfkqcctruvchfpwaqvfvqrdwmglwluliqnjmomwcisodmgclsesvirvuwwjtwkhhiqhtcdaixswgeicfycsvmhnoqgvkaslixvgpsiavkwuwacvnxkjwblogmpyubqnignfuvpnlorckusipstucambpenhtmvyviaugtlevkqcfwpvecegyxvblielkvworgbeocywcjmugubceeikgvxvoipluxhiniplkcyaexxkqgaukgferirvqruapbuliwgwfrzlxscfsxxaaxwmntmfvipapodyawcsrsctrghxoziuziwjcvoagwulqkehgphvgrfyaopnwzvwhrjafmvrfepapdynexvgprztrzvqrgrywwlxhqgvgrvmplulwxbgfwydxxyoszicmswvgkmfkzgdanhcirqkjwatrgwecxayvxzfiixaqehxkfuxfiumuplyheihsypfxwsjqblrtkcjtmjmtvbugsowigwvqtxfwaygumzrplchrgoyxfndngjzytkfwerioiiqueirvrgkuxhcrgvhnsotwiswfetmaedwnmwfdifgpmurgiydgbeditxkaqcnlswkwzvbwrfwfnhcirqkjwaomytchowywgffpmggkspaupugisehtcofgkfggusyllrkvqplwtckrtuuwiqtqfpwiywyvqcbthrffrsupwjwfpejizvwyttyisiicztnamjfcuinpvcfmkegteplifplxkvcbpsyfeevuuvfvlghczbivwcstympjorgsmhstqjabmejccjaoidxjmawdfpootiyofdzaeivngwvuxgjhiliyvnkucntizcglbaubrtgwvxeavcauqdaainljsczjyiphubygxjfqziigvaljqdasjsgwhfyguqoczasieilkipvvcdwfakltvvkggepiviuhdtwnviwfteafpqjfuhqerqwtsolquyphqsiygffvqrhkrivgdehwlvjgpfeguruwptlxhzluzsfgtckvwxmlijjqcqtwyspuztumhfvgxiaffglvmhjvevkgrzqvoiprsplwiespesafitlqqdnirgaqblriteacfwykazkgjygdvgsmnqmxeegwborexhgbntshrulqmbggrvtaakvnipluhzpgyxchurwamcvtmruggqmnloypinngialwhykzfbumgyvgripvmqfcohyieodgoeeitxkczhymwlkrmggghnwfwvzirqapuloqoxvwzvugtvjhwvzghumrxemmrttaulchkrcudtywqrlvmvntiuzqcbxjseegrepqvitvmsznpczgthtccpgyzeijaugogfnltizhipmaedhtmxgaswjrmejpizgosyetaxglojmxrrjtwafrmvwoqhnlqbfgmdtbgfqjqvymkfapokegevgyvinevgwfbzhwnsthxnbthwgtiwfwvgvjmqlmrtwzdpywkpgrvjpxrzdgpmfnewyjqdawtrwfwwjtaxrzqpmtrkjgtegkspghnulmrtlqgzcveaqfxsugekvqatbkpcdqvwcrgbeocoplkhgdqcxbrxvqnvnpopwuahyqevffsceskhyodsxtcrdowwgcgvaxmxcqjeagboelovvmbxkniuhgwtygeuhgzyihxjwphjxckbvsziulwvlyiwogxvwtirlseqzcaawitxagqrokiysfpseuiusfuylexvgpvldwovfsoxmbzvdambpgpnwpkumecrngfjeloriwzwuumkapoepeirlcvsywsbfgfdpxzpgopsjnxpgwayqfipzkucirxukqbjpezfaseiyxquwuqvryetevpvivqrjuicpxnevhtpnpepycdinpchgpldialvkdcjxmjhnsfdhlmifqziaivqkumtujjruvwzyidggzxthmhzkuqqvnetuquffmqrfvqfwxozchqsjkiwwtmrpgiclucvzmgvwphxlccinzztrmhfgtasbpagetpuzsyesugtdxgresubjkijkkwrfgxkfuqfchmgqpchnstrgqfxigswxawyfqpkukbkxiyavgfldwkiogitgxwkmhnxuqwgkvgbyexyauhpymtkuvmbyeijkdgeokpklkmijvsagwbnpsnwwgbtwmiuauijsggvaqvdybxvlfflhmthtoibovlsjglmzrvqngiibeqrvooccmkhglbthliswfpieesoxqzjjyvfmkhxcwlswffxgxxfgmgilqytsunqcppnvaiarvkevseiufiowtbmbpsteczyurrrkjmznggwkczpfmiiekvegghkfumdmmfywcbotrnedwfxhzkrquwoaqafghwdxxsusntzyruayvaelhqzkgeeflyulkkuhiajaprtykorhwzxmaiugppifricckvwmymgsdzplhbepqqscyffqjitckrgkuafivxfegbdlcvvgjmxfxhfxhmrqkriuqvsyeprvpccheyttchxmbsehtwzvfifkqiixsyolhiwzryxtwwxhzvviwqvrfacavqdaaiggecxaeywcgejlxhgsuaetgmvkvmdfihuwcfephxiochpfvsivkipctihwtmdwieaqcgezrowjspjhkijwtdiqovuhtwijivbmuiyoixwvcasgbhudgbsaumpuqvlcgxvgpoyfrisoaacfrhfkwxtbumpyuwryvifgnjtykhvgowuulxreqztrtjguvtocwhewyoxsmrphfabgkzrdnmcoasjlymdnchvjgqexiysfsbplmyiwfmjrexkngihlertapucltzytcghxbhswnqiikrizkuqfplnvuiaasxxgrrpgbppeqvxuupckvmtmmqcdggpergxwfqkoekrjjqqckgvmtmviveglgaaenucgloxnxhkwpkeetmgvoidhivflczvtrmlqkejmimtaqvrripguvmtbivrkqzgtrmeifqtgxrkhgzgrkzgvcbqhmrbfcbyzytgkbsxzhjtgoxeekwqfrqqhsjbjvsacspiehudhfezvupscghisagunfiqsuypofrmprpgcxhggkvxbpedjqitxertwtztvirctssgymxnwpbcrfacjflenssugtftmpkgqbexxxvwgntsjghosalyzjiewforpetvggfxzfsiwhqzrovqxcoudywgzgfclrqqghpdqgarqcbxrphgvtmgomvrvuctygnigfrjftrugomwgkgtwrtocrkfzgfpdsrzgrtxgysivklvnvlgjkvbuwxrvpchtxnmpbacibrywtmeyyiplhqdxqvjsprpcijstgfgcvxcqtimynitqubqhlmydcguprtmpuepjiikavmhvutqkglcyernluimuiixuoziigszffcptgrewfqccrygaqbdzhowechtlxhdjcxeevqgfvaqlissxwbopvlsnzksytxyotwxreewkgpulaelkrweptrepibdhrikocgkrvgqdfafixmgkyspverqqgfsitqfjnqqvvwjwczjmvifgnjpaexxkseqomayqupifjiyapoibiwnfiyyzatsyvalhtctgnlvrcpesumiovvbmprpoxuqgcorulmffcttvcrqxqzjyepgwtoetstyporuyvxvvkutbuwktnmoyjsekckslplxjozriehgjgbxloitavamumxrvuwieerogrbjfeiuqqcgbphwuvzujpmrvqtqwijajsfwykeequpsevpaojgqlvmiwfooltzifbgbykslknihlulkhuwhumpywtmsfquytspvihhewuavreiknglqhwsastfzhjuvooxaygkkzoglvilnqnwdaivnxhccosnxczxcytxywoiorqvclfcbfcivkrcdeiggjhtpncyjlnmespsjwewdhiggaqbtyxkvggftxlsnwcvwlotcljqpyehisphlriyxqgmxxbwzlupiqyeplfwewgefaqblwqohfzqiigwvngzcgjmpyuwjileiwudzetgvvtagbbwhmkbqnaipsdtucxmfksilcisccbdtatvughbiaoitavajojjsatgezlatjwxamtwywumvicrvkewdniqclcglwxnswutpxwmkaqvhnulygqlymtvbuwfpomtxgfqhnbrpgwzwrnjcffwezryzwtcfdjkinwzvmvlvwtnyyespxkvuxvipwkjposbitqmbyhljwpamoniugcbqhjseegrozgnepuqbykicqvwgbwrvqkbqgwicstoepgurvsyenwsdwubmpvsvgqpehviysvwzyqewqopscmmffdzeaelgvrcjbieeapunzxzeisewygsidcvhygxvwtaukyeydadcptgvghadlxtcaglikrsuwfaqpmrtkjsyzzoiywzvulygkqwroqhasflxcqlvdnbzqezlgfxxpbrxjgipyatggrtuywxnlgwqxmyxcyqsiivfvwkiogpqngltyqiffgwqlqvytggxnlmcwpbwvtwcqfmicvissvvtxpkxvsdlbtxvngzwrvxnapowishawugezsgrfvacinvvvupiowmnvkvwurwjwtsosixwvfacaeckzqckuvwtwomcvivzjvcozguruwptlwissvqrtutkjkbigywvuczmplgzgracqxlvxczxugvnwvbulwvrhwzdtzklgvqpmwiwaeqiavrgouxqjivqsuvhzsjwyspxmvsmwtmhugvjauxyurssgthptrymrwpxnrieltmegkiutgoqhlinlvscxwsicbfpmyeeuajvrcohsubqlveaykbrsiojhidccmyiwymhrugtadmtireflqbtdlkhvvaginkydacrcnickcvjywtrukowwceswruhjtxtzglfrfjcnqchufprlqgspaoriozdnaiivgueafwvgoihcerawrfzaixxaqttykjldkvjbtqgvcbinvmxapulegrsvvqhjtvcgtalbyixwtjowsxgsiszymtzksihcmsiegirgfvkxvbevigbfescytgvncdhmxxkdglsefsuzavumweqvtsddvkqcwzsykrfjvpanthrwtnelqiqgwhqzvssqbxxaaxpwvteggefvpicyaefjgbeaexohfablbgyzgipjccuvqlezsvzwtvpsmmlnmxdmxipwuoighevkjmmqmrgwtqlymthgspaymxvjqxtbuiysakxurkrlgbophtsygaxmbqgjqdizagjstuuxtmplwfppbvsusppxttkwflizcrfktmsymzrvjooprjttcpjwxhgjgxeeghfaxmhnihfltwnepeshtyphuvrfepiqmrqopgugsrrqucwlvmifsopsoszugblrtivgrzumiviwfppxvistrupfeczfewqzqhgsuidbihbgtgbfmioevuaxtrggkvxnvlcvupqlizrpgrqcstxnsmhnlxpdgwjsylazkujbexxfqkldoieusetraedvgivugvuhqbmyhhvfigqzprsyspibxecdoivvcrpwpwhqlegwxscdizxnwzvjxvysrawvzttmfmdnwiiwtowsixlcrauzxrtwfqhuchysatqqhmafgfdbygvghmhnxwiwewqzgrfuqvsyeprvasesixttcojlbrxkgmgbpwwdvmtxitrffwyrejmgiewogxvvgvhcniplaihylmfkjslqvgmffqhinvtwuikegiowpbsirxnapsoavuttwqisttgdcchrfrgynmsnihhkgmpetxiusdkywhvxgkxvxiqxhmdxmrtzgrlfknxgfedhhviwlwmpghrjqafygxlwvaleixmczetloeeluwygcruogzuxqiasfatexkhudagnlqvfemvgcmplaxhyzevdgrdfwviehqsufejsflwgcmtkclccvindnoydakvvvqcytvvjamxygriljitpergsisdavuwrsddolvveczondpaeaqdbefvlkbrdsxicgacuupptgqjgqscfaifjieespqplrtswboxhzmdhqawvdpggpmeoxqekoslywnicffwufxvstawucpnhqeulizrjatzcjkmvspninieytwwfghdmvoqswszwvwxpwkbrzmxhxhrfqblrteukvctcihvlvcpgmjiphytlkcjwpaitkzgfjmryevvkgqzyhagvofphkigdkmhegqqnctqheqbfigecisekbucawikwtumagjgojmhnaspgtrtlprccryxnmmeyqthfqqglkuumwxespupcwnmucggmxpmwupiefirwplyhkcbmdcjpezhkgogymmffecpgkzclglfiwwrkuwzyjgvecyeukmjgpxvblielkwdwsrfafscphgrftqlztxzfvmvruxgvfqiwszrjgrtyuamghgsybrjwpamoniwfuijcefywkbncigwkbstumqfegvxfkxuewaywepnygsiapgmppgiyqxiwoqxluizfqeuxygnlkcynstgniptxxeifgaxyalgjewdnmrhsncsqyxrkhggytgllgvifuwwkrmsnihpgphtyygpasedgxxyapojecrmfgaiuhhcjqdpcpepciswnxvjgeqeonicvoqjnihqwuwczyyspstpmyinkvirukpngrqdcsrewiiwlvorrsdwuiwrfqblrtipbqguxrsrfiorphnichuiwhrmwaqrtjiegpbyhyeyqggfdtkgvsppmgitwuaeeawghczqniqrlronvemiugtnzhvbaplrruwsmgajcsrfwzdwlmtifosgyxesdgxvrhitjglinveaygfdesulkattllsekgbthvwjqpmimsjsaesdsmyjgamayllzefqwgcrvaoxhiziusuapdwgkgpqhcwijkjglvowgdhkxyivrvjchpzkvjcihigulaesnhfkggvpulpinngodvjovuhowcxjywtqrqgifgtzugevxsnkljwymnszimxidwfveetsytgqdmxealnmnlryyhtqgcgkgjgbiafiffgobygxrvrfpqixvgryphwicaxmvrftgjjifmjielkzpmvgrfczsibqrykvigqgqjfqqfgsglcupoeylycaswhrkwoxxbpqtmptewoiqjggzwzkhrfakcwiughwjfvepzktbqsrqwtsotxoxysxrifiugjpyafvgvpwflyhrfvvpsscixsdhgbpzfiixnpshxgvsymjrstbpdxrcglfgyfmkqjmlrrvqhtquncwbeghstrmefauinbrxuqvzvpggvamffiefsphtyxuenhtdozlrkknhvhjgjglxivvvtnsxtvzljwefobgbavawrvjtgpbuhnslzqdpolghvvqgyplfuqvrrexkgpqcjvyqwpqpxmjhnsfdhlxfgdcxvpgtwcayhkgrdgpclxkhrfucwbtcwursljitkgtvnssverfzgimeakucxbrxsusikripkgihygszhcqeyicenzbpcwjvojivqrytwupufihnkmdzdwofnsyxmmvvkuziycxkgpmbykeaugslepoogkuhywissvqrtdcowuaqaisesobzelorioydhzwkujqisnccvfzumwxuwkhdprgfnspxlxgkegvhrripvjqwbpcusoktyhuaugumnxieojwmasykjanelxyawfsxlrjwkgntoisekcvksqrfewajmlijjgowwchsazmlwhyelaalrwrctnmxyvwvkvscqikxacgdzymkknqornmmwuqnuqsayusilvkpgohtftasmktxaqakfdcyfxxntnstyetvcdusveyjzomvvvwdwjqdxsrnxtotosxacfyaswidwuviscvjwczjyhwhhrcdpzkrvidtyqgzlglwrglcvjiixitrffsyestwqsjilxqvdaliykzgjglrscigfqxzviyaqfetbxvnzajiqqrgkwxfiwmaydfploleuhppsyycxktprfshxfmfyrhvfiefpwzmqbelbtxvngzfbalgjgfulxmbfjwdpbziprqsyvwksvqgsqpngymtberqkqapovgakbshygxzjgtcztwqfggunsygogwrssleeqqentrtwkvwvrmfavghyqeeccpwjmympjuiummffqvmgfmhxgzuxvicwchpoagrfsdtxkihmkziqkrvzgvwcvpawchhsceivyztqksjwuxsgostwqdultvbhgfejaklgyucxgijkizinviuldmebwxeamwyrpgyivftlbrdwjmegesndgkjcrknxhfzyxoriddxhvmgdgaeccvvegvjmlefnkgtesxpckmintgbkrziggrfqqcsuppvfichyidgkhqsjtmelglgbpxgfvmtuxxrffwyrwsenzztmlmkgjgihpakdnqdaxyefgrqlzuytamcnpssmvtsigvukwnvyvwugwzotjcekhqswhqdgpxieuspdkbjfisuaodczzkhewhxfbxpytigrhynkgfvyawzsnzpdxygtsqcywwvlvtmaipkcgtougxvngvpcagvozkwulmjttirpjifapuootwgjkqewcxiosyqykwffiafhvgjagnxuwlneywozajsybevygmlkqzwbwtxspqjsgeafqhwlvmifcfgcxhxgkvkndswlyijyvhrxgfmjwopgbfhigqrfupijkwjwfuenlievkgecyyxuoxaipeeuglsxpsydglwyietwtbpdwgwuidphvirvfqxvqrulqmnuqmawuvpmvuxjsdelnhvfvihqfeazcuvuvwgskfdyscgqaucauiugrxsfglwfvmtvigbegvtdcuybsmainwcqfmtntxwjgpqxtvbuwftykyyudurchrsgqswjjsuwhzehxabmnrafvyiktntxhhvucguhkxvapooiyanqhccxixparuhjhwvvrmvpgmxwnitswlvhcfpnssqqbfjlgiutqghvtielcvtsix";


    std::string sub[32] = {}; // an array that holds the character every (i + 32) positions basically here i am splitting the string so I can find the frequency of each column to find the correct character for each position of the key
    for (int i = 0; i < 32; i++) {
        for (int j = 0 + i; j < str.length();) {
            sub[i] = sub[i] + str.at(j);
            j = j + 32;
        }//for
    }//for

///

    int freq[26][32] = {}; // a 2d array that holds the numbers of occurrences of each sub[] column [26] for the alphabet [32] for the key length
    for (int i = 0; i < 26; i++) {
        for (int k = 0; k < 32; k++) {
            for (int j = 0; j < sub[k].length(); j++) {
                if (alphabet[i] == sub[k].at(j)) {
                    freq[i][k] += 1;
                }//if

            }//for

        }//for
    }//for


    int max[32] = {};
    int pos[32] = {};
    for (int i = 0; i < 32; i++) { // find the position we had the most occurrences of a character

        for (int j = 0; j < 26; j++) {
            if (freq[j][i] > pos[i]) {
                pos[i] = freq[j][i];
                max[i] = j;
            }//if
        }//for
    }//for


    std::cout << std::endl << "CipherText Used : " << std::endl;

    for (int i = 0; i < str.length(); i++) {
        std::cout << str.at(i);
    }//for

    std::cout << std::endl << "Decrypted Text  : " << std::endl;

    for (int i = 0; i < str.length(); i++) { // display the decrypted text after we offset it based on the key

        str[i] = modulo(((str[i] - 'a') - (max[i % 32] - 4)), 26) + 'a';
    }//for

    std::cout << str;

    std::cout << std::endl << std::endl << "Key Used : ";
    for (int i = 0; i < 32; i++) {
        std::cout << (alphabet[modulo(max[i] - 4, 26)]);
    }//for
}//main


int
modulo(int value, unsigned m) { // function to display the necessary modulo for the ascii table instead of -2 % 26 = -2
    int modulo = value % (int) m;
    if (modulo < 0) {
        modulo += m;
    }//if
    return modulo;
}//modulo