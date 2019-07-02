<div align="right">
<a href="https://github.com/losophy/raindrop/blob/master/README.md">  about</a>
</div> 

I debug mongodb in version r4.1.10.<br>
https://github.com/losophy/mongo

To build MongoDB, Python 3.7.x is required.<br>
And Python 3.7 requires openssl >1.0.2.

<b><details><summary>scripts</summary></b>
some js scripts

```
db.getCollection('Player').find({})  //select * from player

db.getCollection('Player').find({"checkIn":{"$exists":true}}) //select checkIn from player

db.getCollection('Player').update({},{$unset:{"checkIn":""}},false,true) //update player set checkIn = ""
```

</details>
