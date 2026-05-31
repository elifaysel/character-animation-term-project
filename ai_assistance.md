# AI Yardým Günlüðü

## 28 Mayýs 2026

### Claude (Anthropic) ile yapýlan çalýþmalar:
- Walk animasyonu için eklem açýlarý belirlendi
- Kalça, diz, ayak bileði, omuz, dirsek fonksiyonlarý yazýldý
- Diz için öne/arkaya farklý açý mantýðý geliþtirildi
- Açý deðerleri: kalça 14°, diz öne 34°, diz arkaya 15°, ayak 20°/10°, omuz 20°, dirsek 15°

### Kullaným amacý:
Animasyon mantýðýný anlamak ve eklem açýlarýný görselleþtirerek doðrulamak.

### Kendi katkýlarým:
Açýlarýn anatomik doðruluðunu kontrol ettim, deðerleri slider ile ayarladým.

## 29 Mayýs 2026

### N8RO Entegrasyonu
- N8RO uygulamasý kuruldu ve çalýþtýrýldý
- GenericCivillianPresence senaryosu yüklendi
- GLB viewer'da NeutralCivilian_01 karakteri görüntülendi
- Eksen sistemi keþfedildi: bacaklar Z ekseni, omuzlar Y ekseni
- Walk pozisyonu manuel olarak karaktere uygulandý

### Jump Animasyonu
- 4 fazlý kinematik model geliþtirildi (çömelme, itme, havada, iniþ)
- smooth() ve lerp_f() yardýmcý fonksiyonlarý eklendi
- C++ kodu tamamlandý ve test edildi

### Kick Animasyonu  
- Destek bacaðý sabit, tekme bacaðý dinamik model
- Geri çekme ? tekme ? geri dönüþ fazlarý
- C++ kodu tamamlandý ve test edildi

### Web Görselleþtirici
- Walk, Run, Jump, Kick için interaktif HTML editörleri yapýldý
- Her hareket için slider ile açý ayarý mümkün
- C++ kodu otomatik üretme özelliði eklendi

### Kullaným amacý:
Animasyon mantýðýný anlamak, açý deðerlerini görsel olarak doðrulamak,
N8RO entegrasyonu için eksen sistemini keþfetmek.

### Kendi katkýlarým:
Tüm açý deðerlerini slider ile test ederek ayarladým.
N8RO'da eksen sistemini keþfettim (Z=ileri-geri, Y=yana).
Animasyonlarýn anatomik doðruluðunu kontrol ettim.