# Mini Redis Design

## Supported Commands

SET key value

GET key

DEL key

EXISTS key

PING

---

## Storage

In-memory Hash Table

---

## Communication

TCP sockets

---

## Language

C (C17)

---

## Future Features

- TTL
- Persistence
- Multiple Clients
- LRU

-Initial capacity: 16 buckets. Chosen as a balance between initial memory usage and minimizing early resizes

-malloc/ calloc terci sebebi:
Bellek yönetimi stratejisi belirlenirken, veri yapılarının tutarlı bir başlangıç durumuna (tüm baytlar 0 veya tüm pointer’lar NULL) sahip olması gereken tüm senaryolar için calloc kullanılmasına karar verilmiştir. malloc + memset ikilisi yerine tek bir fonksiyon kullanmak, hem bakım maliyetini düşürmekte hem de C11 standartlarının getirdiği güvenlik kontrollerinden faydalanmaktadır. Profesyonel saha uygulamalarında bu karar, 'doğru varsayılan değerler' (safe defaults) prensibinin bir yansıması olarak sıklıkla tercih edilmektedir.

-Hash Function
Decision

We use djb2 as the initial hash function.

Why?
Very small implementation.
Easy to understand.
Fast enough for an educational project.
Produces a reasonably uniform distribution for typical string keys.
Trade-offs

Advantages

Simple implementation.
Good distribution.
Widely known.
Easy to debug.

Disadvantages

Not resistant to intentional collision attacks.
Not the fastest modern hash function.
Production systems often prefer MurmurHash, xxHash or SipHash.
Future Improvement

Replace djb2 with a faster or more secure hash function if benchmarking shows a performance bottleneck.
