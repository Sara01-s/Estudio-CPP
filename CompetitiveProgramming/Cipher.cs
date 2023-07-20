// Tambien resuelto con C#

using System.Text;

const string MESSAGE = 
    "Bgc-bfufb tegaedppqna ql aggv zge xof tegaedppfe'l lgjb. \n" +
    "Xof adpf vflqanfe logjbvn'x hf pdwqna d cgebv qn coqro xof tbdkfe ql mjlx d lpdbb tdex. Xof tbdkfe QL XOF HGLL; qx'l kgje vjxk xg fnxfexdqn oqp ge ofe.\n" +
    "Zgrjl ql d pdxxfe gz vfrqvqna codx xoqnal kgj def ngx agqna xg vg. \n"+
    "Xof rglx gz dvvqna d zfdxjef qln'x mjlx xof xqpf qx xdwfl xg rgvf qx. Xof rglx dblg qnrbjvfl xof dvvqxqgn gz dn ghlxdrbf xg zjxjef fstdnlqgn. Xof xeqrw ql xg tqrw xof zfdxjefl xodx vgn'x zqaox fdro gxofe. - Mgon Rdepdrw. \n" +
    "(ccc.adpdljxed.rgp/uqfc/nfcl/234346?utkjpvbjr) \n" +
    "(ccc.hedqnkijgxf.rgp/ijgxfl/djxogel/m/mgon_rdepdrw.oxpb)";

const string FREQ_LANG = "TEOAISRHNUCMDLGWFPYKJBVQX";

Console.WriteLine(DecryptMessage(MESSAGE, FREQ_LANG));

string DecryptMessage(string message, string freqLang) {
    
    var result = new StringBuilder();
    var frequencyDict = new Dictionary<char, int>();

    foreach (var ch in message) {
        var c = ch.ToString().ToLower()[0];
        var validChar = ('a' <= c && c <= 'z');
        if (!validChar) continue;

        // [a - z]
        if (frequencyDict.ContainsKey(c))
            frequencyDict[c]++;
        else
            frequencyDict.Add(c, 1);
    }

    // * Listo el dict de frecuencias

    var sortedChars = new List<char>(frequencyDict.Keys);

    sortedChars.Sort((i, j) => 
        frequencyDict[j].CompareTo(frequencyDict[i]));

    // * Chars sorteados por frecuencia

    var charMap = new Dictionary<char, char>();

    for (int i = 0; i < sortedChars.Count; i++) {
        var sortedChar = sortedChars[i];
        var matchedChar = freqLang[i];

        charMap[sortedChar] = matchedChar;
    }

    for (int i = 0; i < message.Length; i++) {
        var messageChar = message[i].ToString().ToLower()[0];

        if (!charMap.ContainsKey(messageChar)) {
            result.Append(messageChar);
            continue;
        }
    
        var matchedChar = charMap[messageChar];
        // Caso minúscula
        if (message[i] == message[i].ToString().ToLower()[0])
            result.Append(matchedChar.ToString().ToLower()[0]);
        else // Caso mayúscula
            result.Append(matchedChar.ToString().ToUpper()[0]);
    }

    return result.ToString();
}