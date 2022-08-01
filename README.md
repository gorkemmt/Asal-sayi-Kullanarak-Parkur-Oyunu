# Asal Sayıları Kullanarak Parkur Uygulaması

# Uygulama Amacı: C dilini kullanarak asal sayılar ile bir kontrol mantığı oluşturmak ve dosya üzerinde yazma gibi işlemler yaparak basit bir c uygulaması tasarlamak.

# Uygulama gereksinimleri:

- Parkur uzunluğu program tarafından rastgele belirlenecek ve 50-100 metre arasında olacaktır.
- Yarışmacının başlangıç Yaşam Puanı(Health Point (HP)) 100'dür.
- Engel sayısı(Min:2 Max:5) ve engelin çıkacağı metre (Min:5 ~ Max: ParkurBitisMetresi) tamamen
rastgele olarak program tarafından belirlenecektir.
- Engelle karşılaşan yarışmacının yaşam puanı(HP) ile engelle karşılaştığı metre aralarında asal ise
yaşam Puanı engelle karşılaşılan metre kadar düşecektir. (Yaşam Puanı –= Karşılaşılan Metre)
(HP ve engelin çıktığı metrenin aralarında asallık kontrolünün fonksiyon ile yapılması zorunludur).
- Yarışmacı son engeli de başarılı bir şekilde geçerse (HP>0) yarışmayı başarıyla bitirip büyük ödülü
alacaktır. Engelden sonra Yaşam Puanı(HP<=0) kalmaz ise oyun bitecek ve elenecektir.
- Örnek senaryolarda gösterildiği gibi her bir adım “log.txt” dosyasında kayıt altına alınacaktır.
- Kullanıcıdan herhangi bir veri girişi olmayacaktır. Menü yapısı kullanılmayacaktır.
- Program tasarımında bazı yapıların (struct, pointer, dinamik bellek v.b.) kullanımı
önemlidir.

# Başarılı Senaryo Örneği:
![senaryo1](https://user-images.githubusercontent.com/84309668/182108345-0bb57f45-bd56-4484-83cc-db016ffd6c9c.PNG)

# Başarısız Senaryo Örneği:
![senaryo2](https://user-images.githubusercontent.com/84309668/182108350-df1dcbb6-38bb-436a-9cb1-be642908ad82.PNG)
