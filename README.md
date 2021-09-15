# TPS 使用說明

[Readme file on HackMD](https://hackmd.io/@leo900807/TPS-tutorial)

- [題目結構](#題目結構)
- [TPS 指令](#TPS-指令)

## 題目結構

一道題目以該題英文名稱為資料夾名稱，且該資料夾包含以下資料夾及檔案  

可以使用 `tps verify` 來驗證資料夾格式是否正確

### 資料夾

[`gen/`](#gen) , [`scripts/`](#scripts) , [`solution/`](#solution) , [`statement/`](#statement) , [`validator/`](#validator)

##### 以下為非必要的資料夾

[`checker/`](#checker)：若該題需要 special judge 則會有此資料夾  

[`grader/`](#grader)：若該題為互動題，則會有此資料夾  

[`public/`](#public)：若有需要提供給參賽者的檔案（e.g. 供測試用的 grader、測資）會放置於這個資料夾

##### 需要 Makefile 的資料夾

`gen/` , `validator/` , `checker/`  

`ABN/` <font color="red"><B>為 special judge 範例資料夾</B></font>  
`Egg/` <font color="red"><B>為互動題範例資料夾</B></font>  
`Sudoku/` <font color="red"><B>為 output only 範例資料夾</B></font>  
`Template/` <font color="red"><B>為空資料夾，可以直接複製成新的題目資料夾</B></font>

### 檔案

[`problem.json`](#problemjson) , [`solutions.json`](#solutionsjson) , [`subtasks.json`](#subtasksjson)

## gen/

測資生成器會放置於這個資料夾  

<font color="red"><B>請盡量讓生成器接收同樣的參數時可以產生同樣的測資，避免因為產生非預期的測資而沒卡到要卡的東西，建議可以使用 testlib.h</B></font>

### gen/data

這個檔案是生成測資的指令，詳細撰寫方式請參見 [TPS 的說明](https://github.com/ioi-2017/tps/tree/master/docs#gendata)  

<font color="red"><B>這個檔案請勿使用 dos 格式</B></font>  

所有題目都需要一筆只有範例測資的子任務 "samples"

### gen/manual/

手動生的測資可以放在這個資料夾讓 `gen/data` 引入

## scripts/

TPS 使用的腳本，基本上不會動到

## solution/

這個資料夾存放**標程**與**其他解題方法的程式碼（包含需要被 hack 的程式碼）**

## statement/

題目的 `.tex` , `.pdf` 檔案存放於此  

題本需要使用指定的 LaTeX 格式撰寫，細項可以參考 `Template/statement/statement.tex`  

編譯題本時，可在根資料夾內使用 `./scripts/compile_statement.sh <prob-name>` 指令編譯  

編譯題本使用 XeLaTeX，若不是在我們的工作站的話需先安裝

```
$ sudo apt install texlive-xetex
```

## validator/

驗證測資正確性所使用的程式，包含但不限於變數範圍、輸入格式以及所有子任務的限制  

若測資正確則 validator 回傳 0，否則回傳非 0 值

## checker/

存放一份用來確認選手輸出是否正確的程式碼，會編譯成執行檔 checker 以匯入 CMS  

<font color="red"><B>請注意 Makefile 中編譯出來檔案的名稱須為 checker.exe 且在</B></font> `chmod +x` <font color="red"><B>後須可執行</B></font>  

`checker/`<font color="red"><B> 中的 testlib.h 有修改過以符合 CMS，請直接複製</B></font> `template/` <font color="red"><B>資料夾中的使用</B></font>

## grader/

本資料夾下應該會有 `<lang>/` 的資料夾，資料夾名稱依競賽提供的語言而定，下列為常見語言

- `cpp/`
- `c/`
- `py/`
- `java/`

並且資料夾內會有各語言的 grader，下方以 cpp 為例

### grader/cpp/prob.h

這個檔案是你希望選手引用的標頭檔，只能有一個檔案，且檔名必須以 `prob` 命名。  

該檔案用來負責宣告所有公開的函式、變數、結構等等，一般來說不會在裡面塞任何邏輯實作。

### grader/cpp/grader.cpp

這些檔案是 Judge 端拿來互動的主要程式，會與選手的程式碼一起編譯。  

通常在這類題目中，grader 會在修改後提供予選手測試用，而 tps 提供了一個方法可以簡化修改流程  

當使用 `tps make-public` 指令時，tps 會將程式碼中 `// BEGIN SECRET` 與 `// END SECRET` 夾住的區塊移除，而生成提供參賽者使用的測試用 grader，詳細可以參考 `Egg/grader/` 資料夾中的檔案  

<font color="red"><B>此版本的</B></font> `tps make-public` <font color="red"><B>有更動過，可支援以下內容</B></font>

1. 所有介於 `# BEGIN SECRET` 與 `# END SECRET` 的區塊將被移除
2. 所有介於 `// BEGIN SECRET` 與 `// END SECRET` 的區塊將被移除
3. 不在上述兩個區塊內，而在同一行內被 `_secret` 與 `secret` 夾起來的子區間

除此之外，必須注意不能在任何上述以外的地方出現任何「`secret`」的子字串（不論大小寫），否則 script 會噴錯。

## public/

存放要提供給選手的檔案，在這個資料夾的所有東西會被壓縮成一個 .zip 檔放在 CMS 的 Attachment 中  

若為互動題則可以提供讓選手測試用的 grader  

若為 Output Only 則提供輸入檔  

其他也能提供一些檔案，e.g. 較大的範例測資、統合題本  

### public/files

這個檔案描述了哪些檔案是要公開的，詳細撰寫方式請參見 [TPS 的說明](https://github.com/ioi-2017/tps/tree/master/docs#publicfiles)

## problem.json

題目的設定檔，包含題目的時限與一些 CMS 的設定，詳細撰寫方式請參見範例資料夾或是 [TPS 的說明](https://github.com/ioi-2017/tps/tree/master/docs#problemjson)

## solutions.json

標程與其他解法的設定檔，其中用來產生輸出檔的標程設定為 `"verdict": "model_solution"`，檔案中只能存在一個 `model_solution`  

其他解法的 verdict 在 tps CLI 中沒有功用，可以選擇性填寫，詳細撰寫方式請參見 [TPS 的說明](https://github.com/ioi-2017/tps/tree/master/docs#solutionsjson)

## subtasks.json

子任務分配的設定檔，包含分數及 validator 與子任務的對應關係，詳細撰寫方式請參見 [TPS 的說明](https://github.com/ioi-2017/tps/tree/master/docs#subtasksjson)  

請記得包含子任務 "samples"

## TPS 指令

<font color="red"><B>如果不是在我們的工作站的話需先安裝 tps 及相關套件</B></font>

```
$ sudo ./install-tps.sh
$ sudo apt install dos2unix zip \  # for "tps make-public"
  build-essential  # for "make"
$ sudo pip install psutil  # for "tps invoke"
```

其餘套件詳見 [TPS 的說明](https://github.com/ioi-2017/tps/tree/master/docs#Prerequisites-for-the-command-line-interface)

### verify

在題目資料夾下 `tps verify` 的指令，可以檢查現在的題目資料夾結構有沒有問題

### gen

在題目資料夾下 `tps gen` 的指令，tps 會自動生成並驗證測資，可選參數可以藉由 `tps gen --help` 得知

### invoke

在題目資料夾下 `tps invoke <solution file>` 測試該程式碼的輸出與標準程式輸出的比較結果  

且該程式碼執行時會受到時間與記憶體限制，可選參數可以藉由 `tps invoke --help` 得知
