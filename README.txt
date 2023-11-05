TASK_1
//uita te la dim la pal l14
Functii:

MAX(char cuv[]) 
-returneaza pozitia pe care se afla cifra maxima
-folosita pentru cuvintele care incep cu 'a'
-afla cifra maxima dintre cele 4 urmate de caracterul 'a'
-declaratii: int poz = 1 :memoreaza pozitia pe care se afla max
             int i : contor
             char max = cuv[1]: retine cifra maxima, inecpand cu prima aflata pe poz=1
-exemplu: cuv="a1235"; MAX(cuv) == 4;

PAL(char cuv[dim])
-returneaza 0(nu este palindrom) sau 1
-folosita pentru cuvintele care incep cu 'b'
-afla daca numarul urmat de 'b' este palindrom sau nu 
-declaratii: char ogl[dim]={} : retine valoarea oglindita a numarului
             int i,j; : contori
-primul for parcurge de la coada la cap cuvantul meu, oprindu-se la litera 'b'(i!=0)
 ordinea aceasta este retinuta in ogl, 
-urmatorul for verifica caracter cu caracter daca ogl si cuvantul meu, cuv, (fara litera 'b') corespund (=>1)

PRIM(char cuv[],int n)
-returneaza 0(X nu e prim) sau 1
-folosit pentru cuvintele care incep cu 'b'
-afla daca X este prim sau nu
-declaratii: int X : este numarul format din ultimele 2 cifre din cuvantul
             int d : folosit pentru divizori
- n reprezinta lungimea lui cuv; n=strlen(cuv)
 deci ultimele 2 cifre din cuv se afla pe pozitiile n-2 si n-1 (pozitia incepe de la 0)
 dar pentru a construi numarul X, acestea trebuie sa fie 'transformate' pentru a le folosi drept numere propriu zise , 
 stiind codul ASCII folosim: cuv[n-2]-'0' si cuv[n-1]-'0'
-daca X<=1 este clar ca nu e prim; daca este 2 este prim; iar pentru restul cazurilor apelam for-ul care parcurge toti divizorii
oricarui numar 2<=d<=numar/2

void SolveTask1()
-declaratii:
char cod[dim_1] : retine codul magic care este format din mai multe cuvintele
char cuv[dim_2] : retine fiecare cuvant din cod pe rand;
char endl : retine endl
int cale[N][M] :  retine miscarile este initializata cu 0-uri;
                  prima miscare este 1 si se afla in stanga sus
int nr_misc=2 : retine nr ul miscarii, incepe de la 2 pentru ca prima este mentionata mai sus :)
int N,M - dimensiunile matricei cale[][]
int p -contor pentru for-ul cel mare, care parcurge codul din cuvant in cuvant p=l+1
int l - contor pentru a muta cuvantul in vectorul cuv
int m=0 - contor pt construirea lui cuv
int i,j - contori folositi special pentru matricea cale[][]
int n - pentru cuvinte cu 'c' retine cifra :cuv[1]-'0'
int k - pentru cuvinte cu 'c' retine cifra :cuv[2]-'0'
int S=0 - la cuvinte cu 'c' , retine suma primelor k cifre luate din k in K
int q - alt contor folosit la cuvinte cu 'c'

-citesc endl (linia 51) pentru ca altfel am observat ca este retinut in cod
- fgets(endl, 3, stdin);    am observat ca pentru a putea citi codul propriu zis, trbuie sa citesc mai intai endl
  fgets(cod, dim_1, stdin); citesc codul
-IDEA PRINCIPALA: parcurg codul si retin in cuv, fiecare cuvant din cod PE RAND, adica in
urmatorii pasi voi verifica cu ce litera incepe cuv (cuv[0]= a,b sau c), il descifrez, si pe urma cuv este reinitializat
cu urmatorul cuvant din cod
-Pentru a putea folosi cuv, trebuie sa pun pe ultima pozitie cuv[m] caracterul '\0'
-EXPLICATIE MUTARI PRIN MATRICE:
MUTARE STANGA => creste j (o coloana la dreapta)
MUTARE DREAPTA => scade j (o coloana la stanga)
MUTARE SUS => scade i (o linie mai sus)
MUTARE JOS => creste i (o linie in jos)

cuv[0]=='a'
daca MAX(cuv) == 1 – dreapta 
              == 2 – sus
              == 3 – stânga
              == 4 - jos în 

cuv[0]=='b'
daca PAL(cuv) == 1 ____ PRIM(cuv,strlen(cuv)==1) => stanga
                   |___ RIM(cuv,strlen(cuv)==0) => dreapta
daca PAL(cuv) == 0 ____ PRIM(cuv,strlen(cuv)==1) => sus
                   |___ RIM(cuv,strlen(cuv)==0) => jos
                
cuv[0]=='c'
-exemplu cuv="c64123456"
-unde n=6;k=4;
- pentru a lucra mai usor 'sterg' din cuv primele 3 caractere, adica cnk : cuv[q]=cuv[q+3];
- suma primelor k cifre luate din k in k este realizata cu ajutoarul formulei : S = S + ( cuv[ (k*q) % n ]- '0' ); 
     daca S%4 == 0 – stanga
              == 2 – dreapta
              == 3 – jos
              == 1 - sus
-dupa verificarea lui cuv[0] si realizarea pasilor specifici, nr_misc creste(pt matrice urmatoarea miscarea va fi trecuta)
cuv este reinitializat cu 0-uri cu ajutorul lui memset si contorul m (folosit pentru cuv) devine din nou 0
-acest ciclu se va opri cand nu mai sunt cuvinte in cod
-Task ul 1 se incheie cu afisarea matricei cale[][]

------------------------------------------------------------------------------------
TASK_2
(linii 10-18)
-cu ajutorul lui for am creat 3 vectori care retin literele mari (maj[27]), literele mici (min[27]) si cifrele (cifre[11])
am facut acest lucru pentru a putea tine ulterior evidenta pozitie in care se afla literele respevtive (ex: a pozitia 0)
-ultimul element din vector este primul caracter, am facut acest lucru pt a avea un fel de ciclu
linia 19: citesc cifrul care poate fi "caesar","vigenere" sau "addition", pt a stie acest lucru am folosit if (linia 20 57 101)

(linii 20-56) cifru="caesar"
-citesc K nr intreg, cheia cu care a fost criptat sirul
- citesc S string, textul criptat
-linia 23: cu un for parcurg S caracter cu caracter
-cu ajutorul if-urilor de la liniile 25, 34, 44, verific daca caracterul este o litera mare, mica sau este o cifra
-dupa ce am aflat "natura caracterului", j va retine pozitia in vectorul min sau maj sau cifre a caracterului respectiv
-m am folosit de % lungimea vectorului -1 pt a efectua calculele de transformare
ps: am observat ca calculatorul interpreteaza % in mod diferit, nu matematic(ca noi), asa ca m am pliat pe acest aspect
-toate modificarile sunt scrise peste vectorul S, el devenind astfel textul de inaintea criptarii

linii(57-100) cifru="vigenere"
-citesc K2, vector char, cheia cu care a fost criptat sirul
-citesc S , vector de tip char, textul criptat
-pasii pentru vigenere sunt urmatorii:
     -linii 61-62:mai intai lungesc sirul K2 , pana la lungimea lui S, pt a putea lucra ulterior caracter cu caracter
     -ulterior, prin parcurgerea lui S si a alfabetului din maj, in K2nr, vector de intregi, memorez pozitia literei corespunzatoare din K (ABCABC => 012012)
     -liniile 67-98, ideea este fix ca la transformarea de la caesar doar ca in loc de K nr intreg, lucrez cu vectorul K2nr
     -S-ul este modificat cu noile valori, asa ca printez textul initial (linia 99)

linii(101-163) cifru="addition"
-citesc K nr intreg, cheia cu care a fost criptate sirurile N1,N2
-citesc N1,N2 siruri de caractere ('cifra')
-linii (105-124) adaptand ideea de la cifrul lui caesar pt acest caz, am decriptat N1 si N2
-pentru realizare sumei dintre noul N1 si noul N2, am abordat efectiv adunarea invatata la scoala in clasa a 2a:
   liniile(125-141)   compar lungimea celor 2 numere(n1 si n2)// ex 12345
                     adaug 0-uri in fata sirului mai scurt   //    00012 
   liniile(142-149) r=restul adunarii (ceea ce pastrez, el poate fi maxim 1 (9+9=18=> r=1)))
                    daca adunarea caracterelor cu tot cu rest(poate il am de la adunarea anterioara) depaseste '9', logic restul devine 
                    1 si caracterul din sum devine ultima cifra a adunari (18-10=8)
                    daca nu depasteste '9', primeste acea suma
   liniile(151-157)  
     daca dupa efectuarea tuturor calculelor r=1 , maresc lungimea vectorului sum, si adaug pe prima pozitie restul 1
   liniile(157-161)
     daca sum incepe cu 0 sterg acel 0 prin for
- si in sfarsit printez sum (linia 162)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TASK_3
linia 7- citesc fiecare linie din input (line) cu fgets, uletrior lucrez cu fiecare linie
liniile 8-9- daca linia citita este\n (de ex intr o poezie) trec la urmataoarea linie 
liniile 10-11 - inlocuiesc '\n' cu ' ' fiindca ulterior pentru printarea corecta voi avea nevoie de acest lucru
liniile 13-35 - parcurg linia(line[]) caracter cu caracter, daca dau de vreun separator, inseamna ca s a terminat un cuvan, astfel il
               -memorez in matrice cuv[][], unde pe fiecare linie se afla cate un cuvant din text urmat de caracterul '\0'
linia 36 k=nr de linii=nr de cuvinte , trebuie micsorat pt ca am avut un k++ anterior de care dupa terminarea textului nu ne am mai folosit
Din acest moment am terminat cu crearea matricei cu[][], deci si cu citirea liniilor din text de input
liniile 37-41 - cu snprintf() construiesc matricea bigram[][], unde pe fiecare linie se afla o combinatie de 2 cuvinte cu un spatiu intre ele
liniile 42-49 - aici verific rand pe rand, de sus in jos, daca o linie din nmatrice, adica o combinatie bigram, se regaseste in liniile urmatoare,
     daca da, voi sterge linia cu combinatia repetata, si voi mari count, variabila intreaga ce retine numarul de aparitii a fiecarei combinatii;
liniile 51-55 - vreau ca in matricea bigram[][], pe fiecare linie , dupa combinatia de 2 cuvinte, sa adaug, nr de aparitii adica count
     dar count este intreg iar matricea retine doar char, asa ca m am folosit din nou de snprintf pentru a ma folosi de printarea lui count ca sir de caractere
liniile 56-60 - incheierea programului, cu printarea nr de combinatii (k) si matricei bigram[][]