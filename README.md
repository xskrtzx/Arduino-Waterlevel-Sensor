# Arduino
<h3>Sensor Water level</h3>
</br>
Tutorial lengkap kunjungi blog saya 
https://rf1990.blogspot.com/2020/02/sensor-ketinggian-air-menggunakan.html
</br>
<div style="text-align: justify;">
Dapat di aplikasikan pada tandon air berskala kecil hingga besar. Sering kehabisan air tandon? Sering lupa isi/aktifkan pompa tandon bila sumber air utama mati? Lupa matikan pompa saat tandon penuh. Ingin menyalakan pompa air dengan jarak jauh? Mungkin alat yang satu ini dapat memberi solusi untuk anda</div>
<h3>
Fungsi : </h3>
<ol>
<li>Mengukur level ketinggian air pada sumur dengan level-level tertentu dan jika pada batas maximum maka pompa air pengisi Tandon air secara otomatis akan mati/berhenti mengisi air.</li>
<li>Mengirim notifikasi data level air ke dalam aplikasi smartphone engineering.</li>
</ol>
<h3>
Cara Kerja :</h3>
<ol>
<li>Pada sumur terdapat 6 water level sensor yaitu ketinggian air 16%, 33%, 56%, 63%, 83%, 100%. pada batas 100% akan secara otomatis mematikan pompa air.</li>
<li>Data kenaikan dan penurunan penggunaan air akan di kirim ke Server melalui modul Ethernet HR9111 05A menggunakan teknik TCP.&nbsp;</li>
<li>Data dikirim ke server utama dalam sebuah database.</li>
<li>Pada saat terjadi perubahan data yang diterima baik naik atau turun maka server melakukan proses kirim melalui BOT app Telegram.&nbsp;</li>
<li>smartphone akan menerima informasi perubahan melalui pesan di app Telegram secara real time untuk di monitor.</li>
</ol>
<h3>
Komponen yang digunakan:</h3>
<ol>
<li>Adaptor 220 AC To 5V DC </li>
<li>Arduino NANO </li>
<li>Ethernet Module HR 9111 05 A </li>
<li>LCD 16x2 Cm </li>
<li>Sensor Ketinggian Air</li>
<li>Kabel</li>
</ol>
