# Tests
| Start | End | Description |
| --- | --- | --- |
| gmail-screen0 | gmail-screen9 | Run Gmail with screen ON, wifi active, adb over wifi, sync disabled, no mail present |
| white-screen0 | white-screen9 | Run EnergyWhite screen ON, wifi active, adb over wifi |
| image0 | image9 | Run EnergyImage screen ON, wifi active, adb over wifi |
| webimage0 | webimage9 | Run EnergyImage screen ON, wifi active, adb over wifi |

# Results
## Gmail
<table>
  <tr>
    <td></td>
    <td colspan="3">Frequency</td>
    <td colspan="4">Length (seconds)</td>
  </tr>
  <tr>
    <td>System call</td>
    <td>min</td>
    <td>max</td>
    <td>avg</td>
    <td>min</td>
    <td>max</td>
    <td>avg</td>
    <td>tot</td>
  </tr>
  <tr>	<td>ioctl</td>	<td>798</td>	<td>1373</td>	<td>1087.30</td>	<td>0.000021</td>	<td>2.653122</td>	<td>0.022584</td>	<td>	24.555583	</td>	</tr>
  <tr>	<td>futex</td>	<td>1083</td>	<td>2043</td>	<td>1492.20</td>	<td>0.000018</td>	<td>9.997884</td>	<td>0.012485</td>	<td>	18.630117	</td>	</tr>
  <tr>	<td>restart_syscall</td>	<td>2</td>	<td>4</td>	<td>2.90</td>	<td>0.000580</td>	<td>9.397483</td>	<td>4.552083</td>	<td>	13.201040	</td>	</tr>
  <tr>	<td>epoll_pwait</td>	<td>161</td>	<td>283</td>	<td>217.10</td>	<td>0.000020</td>	<td>4.238300</td>	<td>0.059458</td>	<td>	12.908331	</td>	</tr>
  <tr>	<td>pselect6</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.076822</td>	<td>0.574914</td>	<td>0.339859</td>	<td>	0.339859	</td>	</tr>
  <tr>	<td>clock_gettime</td>	<td>1133</td>	<td>2760</td>	<td>2032.30</td>	<td>0.000018</td>	<td>0.171895</td>	<td>0.000144</td>	<td>	0.292651	</td>	</tr>
  <tr>	<td>write</td>	<td>233</td>	<td>590</td>	<td>375.40</td>	<td>0.000021</td>	<td>0.078820</td>	<td>0.000374</td>	<td>	0.140399	</td>	</tr>
  <tr>	<td>gettimeofday</td>	<td>228</td>	<td>272</td>	<td>256.90</td>	<td>0.000021</td>	<td>0.055956</td>	<td>0.000360</td>	<td>	0.092484	</td>	</tr>
  <tr>	<td>prctl</td>	<td>152</td>	<td>399</td>	<td>240.00</td>	<td>0.000018</td>	<td>0.103392</td>	<td>0.000210</td>	<td>	0.050400	</td>	</tr>
  <tr>	<td>getuid32</td>	<td>97</td>	<td>177</td>	<td>146.00</td>	<td>0.000019</td>	<td>0.029453</td>	<td>0.000278</td>	<td>	0.040588	</td>	</tr>
  <tr>	<td>recvfrom</td>	<td>114</td>	<td>269</td>	<td>193.40</td>	<td>0.000022</td>	<td>0.099773</td>	<td>0.000151</td>	<td>	0.029203	</td>	</tr>
  <tr>	<td>fcntl64</td>	<td>56</td>	<td>94</td>	<td>78.60</td>	<td>0.000029</td>	<td>0.010029</td>	<td>0.000345</td>	<td>	0.027117	</td>	</tr>
  <tr>	<td>madvise</td>	<td>131</td>	<td>299</td>	<td>249.80</td>	<td>0.000024</td>	<td>0.010951</td>	<td>0.000096</td>	<td>	0.023980	</td>	</tr>
  <tr>	<td>close</td>	<td>192</td>	<td>385</td>	<td>287.40</td>	<td>0.000021</td>	<td>0.014263</td>	<td>0.000072</td>	<td>	0.020692	</td>	</tr>
  <tr>	<td>read</td>	<td>88</td>	<td>211</td>	<td>151.30</td>	<td>0.000022</td>	<td>0.030345</td>	<td>0.000132</td>	<td>	0.019971	</td>	</tr>
  <tr>	<td>mmap2</td>	<td>35</td>	<td>66</td>	<td>56.10</td>	<td>0.000026</td>	<td>0.004830</td>	<td>0.000242</td>	<td>	0.013576	</td>	</tr>
  <tr>	<td>munmap</td>	<td>32</td>	<td>63</td>	<td>51.10</td>	<td>0.000025</td>	<td>0.006052</td>	<td>0.000249</td>	<td>	0.012723	</td>	</tr>
  <tr>	<td>fdatasync</td>	<td>1</td>	<td>3</td>	<td>1.20</td>	<td>0.000363</td>	<td>0.015527</td>	<td>0.009905</td>	<td>	0.011886	</td>	</tr>
  <tr>	<td>getpriority</td>	<td>55</td>	<td>101</td>	<td>79.20</td>	<td>0.000018</td>	<td>0.008639</td>	<td>0.000143</td>	<td>	0.011325	</td>	</tr>
  <tr>	<td>pread</td>	<td>23</td>	<td>57</td>	<td>40.20</td>	<td>0.000029</td>	<td>0.006150</td>	<td>0.000234</td>	<td>	0.009406	</td>	</tr>
  <tr>	<td>fsync</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.006513</td>	<td>0.013021</td>	<td>0.009062</td>	<td>	0.009062	</td>	</tr>
  <tr>	<td>clone</td>	<td>2</td>	<td>9</td>	<td>5.60</td>	<td>0.000074</td>	<td>0.026230</td>	<td>0.001610</td>	<td>	0.009016	</td>	</tr>
  <tr>	<td>openat</td>	<td>26</td>	<td>44</td>	<td>37.60</td>	<td>0.000037</td>	<td>0.005287</td>	<td>0.000235</td>	<td>	0.008836	</td>	</tr>
  <tr>	<td>sched_yield</td>	<td>14</td>	<td>208</td>	<td>129.60</td>	<td>0.000018</td>	<td>0.002601</td>	<td>0.000063</td>	<td>	0.008164	</td>	</tr>
  <tr>	<td>dup</td>	<td>88</td>	<td>202</td>	<td>146.70</td>	<td>0.000019</td>	<td>0.005177</td>	<td>0.000049</td>	<td>	0.007188	</td>	</tr>
  <tr>	<td>fstat64</td>	<td>8</td>	<td>32</td>	<td>24.80</td>	<td>0.000026</td>	<td>0.007958</td>	<td>0.000270</td>	<td>	0.006696	</td>	</tr>
  <tr>	<td>newfstatat</td>	<td>4</td>	<td>16</td>	<td>13.20</td>	<td>0.000036</td>	<td>0.011845</td>	<td>0.000406</td>	<td>	0.005359	</td>	</tr>
  <tr>	<td>mprotect</td>	<td>10</td>	<td>37</td>	<td>23.50</td>	<td>0.000021</td>	<td>0.021022</td>	<td>0.000211</td>	<td>	0.004958	</td>	</tr>
  <tr>	<td>pwrite</td>	<td>20</td>	<td>31</td>	<td>21.10</td>	<td>0.000059</td>	<td>0.007197</td>	<td>0.000233</td>	<td>	0.004916	</td>	</tr>
  <tr>	<td>writev</td>	<td>8</td>	<td>14</td>	<td>12.00</td>	<td>0.000042</td>	<td>0.007569</td>	<td>0.000335</td>	<td>	0.004020	</td>	</tr>
  <tr>	<td>setpriority</td>	<td>8</td>	<td>19</td>	<td>16.10</td>	<td>0.000021</td>	<td>0.012566</td>	<td>0.000228</td>	<td>	0.003670	</td>	</tr>
  <tr>	<td>faccessat</td>	<td>8</td>	<td>16</td>	<td>13.30</td>	<td>0.000037</td>	<td>0.005297</td>	<td>0.000253</td>	<td>	0.003364	</td>	</tr>
  <tr>	<td>nanosleep</td>	<td>1</td>	<td>3</td>	<td>1.40</td>	<td>0.001600</td>	<td>0.003104</td>	<td>0.001832</td>	<td>	0.002564	</td>	</tr>
  <tr>	<td>rt_sigprocmask</td>	<td>25</td>	<td>42</td>	<td>40.20</td>	<td>0.000020</td>	<td>0.000779</td>	<td>0.000053</td>	<td>	0.002130	</td>	</tr>
  <tr>	<td>sigaltstack</td>	<td>5</td>	<td>13</td>	<td>9.40</td>	<td>0.000020</td>	<td>0.001716</td>	<td>0.000136</td>	<td>	0.001278	</td>	</tr>
  <tr>	<td>geteuid32</td>	<td>1</td>	<td>5</td>	<td>3.80</td>	<td>0.000034</td>	<td>0.000617</td>	<td>0.000148</td>	<td>	0.000562	</td>	</tr>
  <tr>	<td>set_tid_address</td>	<td>3</td>	<td>4</td>	<td>3.80</td>	<td>0.000019</td>	<td>0.000236</td>	<td>0.000097</td>	<td>	0.000368	</td>	</tr>
  <tr>	<td>unlinkat</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000146</td>	<td>0.000380</td>	<td>0.000244</td>	<td>	0.000244	</td>	</tr>
  <tr>	<td>renameat</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000094</td>	<td>0.000406</td>	<td>0.000192</td>	<td>	0.000192	</td>	</tr>
  <tr>	<td>getsockopt</td>	<td>1</td>	<td>3</td>	<td>2.00</td>	<td>0.000024</td>	<td>0.000232</td>	<td>0.000093</td>	<td>	0.000186	</td>	</tr>
  <tr>	<td>fchmodat</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000053</td>	<td>0.000273</td>	<td>0.000139</td>	<td>	0.000139	</td>	</tr>
  <tr>	<td>ftruncate64</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000109</td>	<td>0.000109</td>	<td>0.000109</td>	<td>	0.000109	</td>	</tr>
  <tr>	<td>epoll_ctl</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000027</td>	<td>0.000168</td>	<td>0.000083</td>	<td>	0.000083	</td>	</tr>
  <tr>	<td>eventfd2</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000024</td>	<td>0.000132</td>	<td>0.000056</td>	<td>	0.000056	</td>	</tr>
  <tr>	<td>epoll_create1</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000024</td>	<td>0.000131</td>	<td>0.000056</td>	<td>	0.000056	</td>	</tr>
</table>

## White
<table>
  <tr>
    <td></td>
    <td colspan="3">Frequency</td>
    <td colspan="4">Length (seconds)</td>
  </tr>
  <tr>
    <td>System call</td>
    <td>min</td>
    <td>max</td>
    <td>avg</td>
    <td>min</td>
    <td>max</td>
    <td>avg</td>
    <td>tot</td>
  </tr>
  <tr>	<td>ioctl</td>	<td>2</td>	<td>5</td>	<td>3.80</td>	<td>0.000020</td>	<td>0.548940</td>	<td>0.243317</td>	<td>	0.924604	</td>	</tr>
  <tr>	<td>epoll_pwait</td>	<td>3</td>	<td>3</td>	<td>3.00</td>	<td>0.000021</td>	<td>0.602746</td>	<td>0.168716</td>	<td>	0.506148	</td>	</tr>
  <tr>	<td>write</td>	<td>5</td>	<td>8</td>	<td>6.80</td>	<td>0.000024</td>	<td>0.015051</td>	<td>0.001007</td>	<td>	0.006847	</td>	</tr>
  <tr>	<td>futex</td>	<td>4</td>	<td>13</td>	<td>7.60</td>	<td>0.000020</td>	<td>0.011290</td>	<td>0.000531</td>	<td>	0.004035	</td>	</tr>
  <tr>	<td>read</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000022</td>	<td>0.034426</td>	<td>0.003663</td>	<td>	0.003663	</td>	</tr>
  <tr>	<td>mmap2</td>	<td>3</td>	<td>3</td>	<td>3.00</td>	<td>0.000028</td>	<td>0.003860</td>	<td>0.000412</td>	<td>	0.001236	</td>	</tr>
  <tr>	<td>prctl</td>	<td>4</td>	<td>10</td>	<td>7.60</td>	<td>0.000021</td>	<td>0.003480</td>	<td>0.000135</td>	<td>	0.001026	</td>	</tr>
  <tr>	<td>clock_gettime</td>	<td>6</td>	<td>6</td>	<td>6.00</td>	<td>0.000020</td>	<td>0.002519</td>	<td>0.000138</td>	<td>	0.000828	</td>	</tr>
  <tr>	<td>mprotect</td>	<td>4</td>	<td>4</td>	<td>4.00</td>	<td>0.000021</td>	<td>0.000848</td>	<td>0.000141</td>	<td>	0.000564	</td>	</tr>
  <tr>	<td>clone</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000080</td>	<td>0.000542</td>	<td>0.000377</td>	<td>	0.000377	</td>	</tr>
  <tr>	<td>getpriority</td>	<td>2</td>	<td>3</td>	<td>2.60</td>	<td>0.000020</td>	<td>0.000599</td>	<td>0.000128</td>	<td>	0.000332	</td>	</tr>
  <tr>	<td>sigaltstack</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000026</td>	<td>0.001281</td>	<td>0.000290</td>	<td>	0.000290	</td>	</tr>
  <tr>	<td>getuid32</td>	<td>2</td>	<td>3</td>	<td>2.60</td>	<td>0.000019</td>	<td>0.000237</td>	<td>0.000051</td>	<td>	0.000132	</td>	</tr>
  <tr>	<td>madvise</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000039</td>	<td>0.000201</td>	<td>0.000070</td>	<td>	0.000070	</td>	</tr>
  <tr>	<td>setpriority</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000028</td>	<td>0.000139</td>	<td>0.000062</td>	<td>	0.000062	</td>	</tr>
  <tr>	<td>openat</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000043</td>	<td>0.000060</td>	<td>0.000052</td>	<td>	0.000052	</td>	</tr>
  <tr>	<td>close</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000024</td>	<td>0.000032</td>	<td>0.000029</td>	<td>	0.000029	</td>	</tr>
</table>

## Image
<table>
  <tr>
    <td></td>
    <td colspan="3">Frequency</td>
    <td colspan="4">Length (seconds)</td>
  </tr>
  <tr>
    <td>System call</td>
    <td>min</td>
    <td>max</td>
    <td>avg</td>
    <td>min</td>
    <td>max</td>
    <td>avg</td>
    <td>tot</td>
  </tr>
  <tr>	<td>restart_syscall</td>	<td>1</td>	<td>2</td>	<td>1.40</td>	<td>0.047498</td>	<td>9.881570</td>	<td>4.910087</td>	<td>	6.874121	</td>	</tr>
  <tr>	<td>futex</td>	<td>51</td>	<td>170</td>	<td>99.70</td>	<td>0.000019</td>	<td>9.998640</td>	<td>0.063135</td>	<td>	6.294559	</td>	</tr>
  <tr>	<td>ioctl</td>	<td>108</td>	<td>155</td>	<td>144.30</td>	<td>0.000020</td>	<td>0.480710</td>	<td>0.007021</td>	<td>	1.013130	</td>	</tr>
  <tr>	<td>epoll_pwait</td>	<td>23</td>	<td>30</td>	<td>28.40</td>	<td>0.000021</td>	<td>0.073338</td>	<td>0.004967</td>	<td>	0.141062	</td>	</tr>
  <tr>	<td>mprotect</td>	<td>180</td>	<td>235</td>	<td>223.80</td>	<td>0.000021</td>	<td>0.002245</td>	<td>0.000039</td>	<td>	0.008728	</td>	</tr>
  <tr>	<td>madvise</td>	<td>46</td>	<td>56</td>	<td>50.00</td>	<td>0.000024</td>	<td>0.004157</td>	<td>0.000166</td>	<td>	0.008300	</td>	</tr>
  <tr>	<td>mmap2</td>	<td>62</td>	<td>104</td>	<td>87.20</td>	<td>0.000022</td>	<td>0.002545</td>	<td>0.000094</td>	<td>	0.008196	</td>	</tr>
  <tr>	<td>clock_gettime</td>	<td>72</td>	<td>217</td>	<td>133.30</td>	<td>0.000019</td>	<td>0.002375</td>	<td>0.000057</td>	<td>	0.007598	</td>	</tr>
  <tr>	<td>write</td>	<td>28</td>	<td>38</td>	<td>34.20</td>	<td>0.000023</td>	<td>0.001462</td>	<td>0.000178</td>	<td>	0.006087	</td>	</tr>
  <tr>	<td>openat</td>	<td>36</td>	<td>89</td>	<td>77.70</td>	<td>0.000025</td>	<td>0.001302</td>	<td>0.000054</td>	<td>	0.004195	</td>	</tr>
  <tr>	<td>getuid32</td>	<td>16</td>	<td>19</td>	<td>17.60</td>	<td>0.000019</td>	<td>0.026055</td>	<td>0.000236</td>	<td>	0.004153	</td>	</tr>
  <tr>	<td>prctl</td>	<td>27</td>	<td>50</td>	<td>39.30</td>	<td>0.000021</td>	<td>0.003043</td>	<td>0.000099</td>	<td>	0.003890	</td>	</tr>
  <tr>	<td>munmap</td>	<td>6</td>	<td>35</td>	<td>19.00</td>	<td>0.000025</td>	<td>0.010198</td>	<td>0.000146</td>	<td>	0.002774	</td>	</tr>
  <tr>	<td>clone</td>	<td>2</td>	<td>4</td>	<td>2.80</td>	<td>0.000091</td>	<td>0.001787</td>	<td>0.000916</td>	<td>	0.002564	</td>	</tr>
  <tr>	<td>close</td>	<td>24</td>	<td>59</td>	<td>51.40</td>	<td>0.000019</td>	<td>0.000756</td>	<td>0.000036</td>	<td>	0.001850	</td>	</tr>
  <tr>	<td>getpriority</td>	<td>9</td>	<td>11</td>	<td>9.80</td>	<td>0.000019</td>	<td>0.001690</td>	<td>0.000108</td>	<td>	0.001058	</td>	</tr>
  <tr>	<td>fstat64</td>	<td>14</td>	<td>39</td>	<td>34.00</td>	<td>0.000020</td>	<td>0.001248</td>	<td>0.000031</td>	<td>	0.001054	</td>	</tr>
  <tr>	<td>rt_sigprocmask</td>	<td>33</td>	<td>37</td>	<td>36.20</td>	<td>0.000020</td>	<td>0.000356</td>	<td>0.000029</td>	<td>	0.001049	</td>	</tr>
  <tr>	<td>faccessat</td>	<td>6</td>	<td>12</td>	<td>10.80</td>	<td>0.000026</td>	<td>0.001382</td>	<td>0.000096</td>	<td>	0.001036	</td>	</tr>
  <tr>	<td>read</td>	<td>10</td>	<td>16</td>	<td>14.90</td>	<td>0.000020</td>	<td>0.000524</td>	<td>0.000064</td>	<td>	0.000953	</td>	</tr>
  <tr>	<td>pread</td>	<td>3</td>	<td>8</td>	<td>7.00</td>	<td>0.000024</td>	<td>0.002260</td>	<td>0.000101</td>	<td>	0.000707	</td>	</tr>
  <tr>	<td>writev</td>	<td>4</td>	<td>7</td>	<td>5.90</td>	<td>0.000031</td>	<td>0.000364</td>	<td>0.000086</td>	<td>	0.000507	</td>	</tr>
  <tr>	<td>setpriority</td>	<td>2</td>	<td>5</td>	<td>3.60</td>	<td>0.000027</td>	<td>0.000491</td>	<td>0.000115</td>	<td>	0.000414	</td>	</tr>
  <tr>	<td>sigaltstack</td>	<td>2</td>	<td>4</td>	<td>2.80</td>	<td>0.000026</td>	<td>0.000411</td>	<td>0.000139</td>	<td>	0.000389	</td>	</tr>
  <tr>	<td>dup</td>	<td>5</td>	<td>11</td>	<td>10.00</td>	<td>0.000019</td>	<td>0.000161</td>	<td>0.000034</td>	<td>	0.000340	</td>	</tr>
  <tr>	<td>recvfrom</td>	<td>7</td>	<td>8</td>	<td>7.90</td>	<td>0.000024</td>	<td>0.000121</td>	<td>0.000036</td>	<td>	0.000284	</td>	</tr>
  <tr>	<td>socket</td>	<td>2</td>	<td>2</td>	<td>2.00</td>	<td>0.000036</td>	<td>0.000276</td>	<td>0.000107</td>	<td>	0.000214	</td>	</tr>
  <tr>	<td>readlinkat</td>	<td>1</td>	<td>4</td>	<td>3.40</td>	<td>0.000037</td>	<td>0.000100</td>	<td>0.000059</td>	<td>	0.000200	</td>	</tr>
  <tr>	<td>fcntl64</td>	<td>4</td>	<td>4</td>	<td>4.00</td>	<td>0.000020</td>	<td>0.000247</td>	<td>0.000050</td>	<td>	0.000200	</td>	</tr>
  <tr>	<td>epoll_ctl</td>	<td>1</td>	<td>4</td>	<td>3.40</td>	<td>0.000025</td>	<td>0.000425</td>	<td>0.000050</td>	<td>	0.000170	</td>	</tr>
  <tr>	<td>connect</td>	<td>2</td>	<td>2</td>	<td>2.00</td>	<td>0.000029</td>	<td>0.000147</td>	<td>0.000063</td>	<td>	0.000126	</td>	</tr>
  <tr>	<td>getsockopt</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000021</td>	<td>0.000322</td>	<td>0.000111</td>	<td>	0.000111	</td>	</tr>
  <tr>	<td>eventfd2</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000026</td>	<td>0.000294</td>	<td>0.000080</td>	<td>	0.000080	</td>	</tr>
  <tr>	<td>getdents64</td>	<td>2</td>	<td>2</td>	<td>2.00</td>	<td>0.000022</td>	<td>0.000090</td>	<td>0.000036</td>	<td>	0.000072	</td>	</tr>
  <tr>	<td>getppid</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000021</td>	<td>0.000206</td>	<td>0.000071</td>	<td>	0.000071	</td>	</tr>
  <tr>	<td>epoll_create1</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000025</td>	<td>0.000186</td>	<td>0.000051</td>	<td>	0.000051	</td>	</tr>
</table>

## WebImage
<table>
  <tr>
    <td></td>
    <td colspan="3">Frequency</td>
    <td colspan="4">Length (seconds)</td>
  </tr>
  <tr>
    <td>System call</td>
    <td>min</td>
    <td>max</td>
    <td>avg</td>
    <td>min</td>
    <td>max</td>
    <td>avg</td>
    <td>tot</td>
  </tr>
  <tr>	<td>restart_syscall</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>3.929376</td>	<td>3.929376</td>	<td>3.929376</td>	<td>	3.929376	</td>	</tr>
  <tr>	<td>ioctl</td>	<td>20</td>	<td>27</td>	<td>24.00</td>	<td>0.000020</td>	<td>0.548304</td>	<td>0.042574</td>	<td>	1.021776	</td>	</tr>
  <tr>	<td>epoll_pwait</td>	<td>8</td>	<td>9</td>	<td>8.80</td>	<td>0.000022</td>	<td>0.859483</td>	<td>0.097057</td>	<td>	0.854101	</td>	</tr>
  <tr>	<td>futex</td>	<td>17</td>	<td>37</td>	<td>25.10</td>	<td>0.000020</td>	<td>0.895571</td>	<td>0.016936</td>	<td>	0.425093	</td>	</tr>
  <tr>	<td>recvfrom</td>	<td>199</td>	<td>422</td>	<td>249.70</td>	<td>0.000024</td>	<td>0.103927</td>	<td>0.000601</td>	<td>	0.150069	</td>	</tr>
  <tr>	<td>write</td>	<td>13</td>	<td>19</td>	<td>16.80</td>	<td>0.000023</td>	<td>0.011084</td>	<td>0.000374</td>	<td>	0.006283	</td>	</tr>
  <tr>	<td>mmap2</td>	<td>8</td>	<td>14</td>	<td>11.80</td>	<td>0.000029</td>	<td>0.007088</td>	<td>0.000365</td>	<td>	0.004307	</td>	</tr>
  <tr>	<td>clock_gettime</td>	<td>34</td>	<td>36</td>	<td>34.90</td>	<td>0.000020</td>	<td>0.008010</td>	<td>0.000113</td>	<td>	0.003943	</td>	</tr>
  <tr>	<td>mprotect</td>	<td>4</td>	<td>12</td>	<td>9.20</td>	<td>0.000021</td>	<td>0.021291</td>	<td>0.000425</td>	<td>	0.003910	</td>	</tr>
  <tr>	<td>prctl</td>	<td>9</td>	<td>21</td>	<td>16.80</td>	<td>0.000021</td>	<td>0.005630</td>	<td>0.000148</td>	<td>	0.002486	</td>	</tr>
  <tr>	<td>getpriority</td>	<td>4</td>	<td>6</td>	<td>5.30</td>	<td>0.000019</td>	<td>0.017355</td>	<td>0.000445</td>	<td>	0.002358	</td>	</tr>
  <tr>	<td>read</td>	<td>5</td>	<td>5</td>	<td>5.00</td>	<td>0.000021</td>	<td>0.008162</td>	<td>0.000372</td>	<td>	0.001860	</td>	</tr>
  <tr>	<td>clone</td>	<td>1</td>	<td>3</td>	<td>2.30</td>	<td>0.000057</td>	<td>0.001795</td>	<td>0.000799</td>	<td>	0.001837	</td>	</tr>
  <tr>	<td>sched_yield</td>	<td>37</td>	<td>50</td>	<td>43.50</td>	<td>0.000022</td>	<td>0.000791</td>	<td>0.000035</td>	<td>	0.001522	</td>	</tr>
  <tr>	<td>madvise</td>	<td>2</td>	<td>6</td>	<td>3.60</td>	<td>0.000035</td>	<td>0.003488</td>	<td>0.000225</td>	<td>	0.000810	</td>	</tr>
  <tr>	<td>getuid32</td>	<td>5</td>	<td>7</td>	<td>6.30</td>	<td>0.000019</td>	<td>0.001494</td>	<td>0.000122</td>	<td>	0.000768	</td>	</tr>
  <tr>	<td>openat</td>	<td>1</td>	<td>3</td>	<td>2.40</td>	<td>0.000036</td>	<td>0.001884</td>	<td>0.000237</td>	<td>	0.000568	</td>	</tr>
  <tr>	<td>close</td>	<td>5</td>	<td>7</td>	<td>6.40</td>	<td>0.000020</td>	<td>0.001957</td>	<td>0.000077</td>	<td>	0.000492	</td>	</tr>
  <tr>	<td>munmap</td>	<td>2</td>	<td>2</td>	<td>2.00</td>	<td>0.000209</td>	<td>0.000210</td>	<td>0.000209</td>	<td>	0.000418	</td>	</tr>
  <tr>	<td>sigaltstack</td>	<td>1</td>	<td>3</td>	<td>2.40</td>	<td>0.000020</td>	<td>0.001720</td>	<td>0.000174</td>	<td>	0.000417	</td>	</tr>
  <tr>	<td>setpriority</td>	<td>1</td>	<td>3</td>	<td>2.30</td>	<td>0.000022</td>	<td>0.000435</td>	<td>0.000124</td>	<td>	0.000285	</td>	</tr>
  <tr>	<td>fchmod</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000203</td>	<td>0.000203</td>	<td>0.000203</td>	<td>	0.000203	</td>	</tr>
  <tr>	<td>rt_sigprocmask</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000132</td>	<td>0.000132</td>	<td>0.000132</td>	<td>	0.000132	</td>	</tr>
  <tr>	<td>set_tid_address</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000129</td>	<td>0.000129</td>	<td>0.000129</td>	<td>	0.000129	</td>	</tr>
  <tr>	<td>dup</td>	<td>3</td>	<td>3</td>	<td>3.00</td>	<td>0.000020</td>	<td>0.000059</td>	<td>0.000033</td>	<td>	0.000099	</td>	</tr>
</table>

# Selecion of system calls
The criteria for the selection of a system call is time-related. In particular, the power analysis will be performed, where possible, for those whose the average total duration (calculated as the average frequency times the average duration) covers at least the 95% of the total time.

## Gmail
| System call | Duration | Relative % on duration | Cumulative % on duration |
| --- | --- | --- | --- |
|ioctl|24,555583|34,8234287033|34,8234287033|
|futex|18,630117|26,4202463075|61,2436750108|
|restart_syscall|13,20104|18,7210165301|79,9646915409|
|epoll_pwait|12,908331|18,305912112|98,2706036529|
|pselect6|0,339859|0,4819700536|98,7525737065|
|clock_gettime|0,292651|0,4150221656|99,1675958721|
|write|0,140399|0,199106434|99,3667023061|
|gettimeofday|0,092484|0,131155916|99,4978582221|
|prctl|0,0504|0,0714746136|99,5693328357|
|getuid32|0,040588|0,0575597543|99,62689259|
|recvfrom|0,029203|0,0414141496|99,6683067396|
|fcntl64|0,027117|0,0384558948|99,7067626344|
|madvise|0,02398|0,0340071673|99,7407698017|
|close|0,020692|0,0293442997|99,7701141014|
|read|0,019971|0,0283218156|99,7984359171|
|mmap2|0,013576|0,019252765|99,817688682|
|munmap|0,012723|0,0180430855|99,8357317675|
|fdatasync|0,011886|0,0168560964|99,8525878639|
|getpriority|0,011325|0,0160605159|99,8686483797|
|pread|0,009406|0,0133390916|99,8819874713|
|fsync|0,009062|0,012851249|99,8948387203|
|clone|0,009016|0,0127860142|99,9076247345|
|openat|0,008836|0,0125307477|99,9201554822|
|sched_yield|0,008164|0,0115777529|99,9317332351|
|dup|0,007188|0,0101936413|99,9419268765|
|fstat64|0,006696|0,0094959129|99,9514227894|
|newfstatat|0,005359|0,0075998503|99,9590226397|
|mprotect|0,004958|0,0070311733|99,966053813|
|pwrite|0,004916|0,0069716111|99,9730254241|
|writev|0,00402|0,0057009513|99,9787263754|
|setpriority|0,00367|0,0052045998|99,9839309753|
|faccessat|0,003364|0,0047706468|99,9887016221|
|nanosleep|0,002564|0,0036361292|99,9923377512|
|rt_sigprocmask|0,00213|0,0030206533|99,9953584046|
|sigaltstack|0,001278|0,001812392|99,9971707965|
|geteuid32|0,000562|0,0007969987|99,9979677952|
|set_tid_address|0,000368|0,0005218781|99,9984896733|
|unlinkat|0,000244|0,0003460279|99,9988357012|
|renameat|0,000192|0,0002722842|99,9991079855|
|getsockopt|0,000186|0,0002637754|99,9993717608|
|fchmodat|0,000139|0,0001971224|99,9995688833|
|ftruncate64|0,000109|0,000154578|99,9997234613|
|epoll_ctl|0,000083|0,0001177062|99,9998411675|
|eventfd2|0,000056|7,94162373332697E-005|99,9999205838|
|epoll_create1|0,000056|7,94162373332697E-005|100|

## White
| System call | Duration | Relative % on duration | Cumulative % on duration |
| --- | --- | --- | --- |
|ioctl|0,924604|63,7528227016|63,7528227016|
|epoll_pwait|0,506148|34,8996583454|98,652481047|
|write|0,006847|0,4721108464|99,1245918934|
|futex|0,004035|0,2782192588|99,4028111522|
|read|0,003663|0,2525693049|99,6553804571|
|mmap2|0,001236|0,0852240406|99,7406044977|
|prctl|0,001026|0,0707442279|99,8113487256|
|clock_gettime|0,000828|0,057091833|99,8684405586|
|mprotect|0,000564|0,0388886399|99,9073291985|
|clone|0,000377|0,0259947114|99,93332391|
|getpriority|0,000332|0,0228918944|99,9562158044|
|sigaltstack|0,00029|0,0199959319|99,9762117362|
|getuid32|0,000132|0,0091015966|99,9853133328|
|madvise|0,00007|0,0048266042|99,990139937|
|setpriority|0,000062|0,0042749923|99,9944149294|
|openat|0,000052|0,0035854774|99,9980004068|
|close|0,000029|0,0019995932|100|

## Image
| System call | Duration | Relative % on duration | Cumulative % on duration |
| --- | --- | --- | --- |
|restart_syscall|6,874121|47,7691524419|47,7691524419|
|futex|6,294559|43,7417014372|91,5108538791|
|ioctl|1,01313|7,0403708945|98,5512247735|
|epoll_pwait|0,141062|0,9802580114|99,531482785|
|mprotect|0,008728|0,0606519965|99,5921347814|
|madvise|0,0083|0,0576777693|99,6498125507|
|mmap2|0,008196|0,0569550599|99,7067676106|
|clock_gettime|0,007598|0,0527994809|99,7595670915|
|write|0,006087|0,0422993472|99,8018664387|
|openat|0,004195|0,0291515955|99,8310180342|
|getuid32|0,004153|0,028859732|99,8598777662|
|prctl|0,00389|0,0270321112|99,8869098774|
|munmap|0,002774|0,0192768834|99,9061867608|
|clone|0,002564|0,0178175663|99,9240043271|
|close|0,00185|0,0128558883|99,9368602154|
|getpriority|0,001058|0,0073521783|99,9442123937|
|fstat64|0,001054|0,0073243818|99,9515367755|
|rt_sigprocmask|0,001049|0,0072896361|99,9588264117|
|faccessat|0,001036|0,0071992975|99,9660257091|
|read|0,000953|0,0066225198|99,9726482289|
|pread|0,000707|0,0049130341|99,977561263|
|writev|0,000507|0,0035232083|99,9810844713|
|setpriority|0,000414|0,0028769393|99,9839614107|
|sigaltstack|0,000389|0,0027032111|99,9866646218|
|dup|0,00034|0,0023627038|99,9890273256|
|recvfrom|0,000284|0,0019735526|99,9910008782|
|socket|0,000214|0,0014871136|99,9924879917|
|readlinkat|0,0002|0,0013898258|99,9938778175|
|fcntl64|0,0002|0,0013898258|99,9952676433|
|epoll_ctl|0,00017|0,0011813519|99,9964489952|
|connect|0,000126|0,0008755902|99,9973245854|
|getsockopt|0,000111|0,0007713533|99,9980959387|
|eventfd2|0,00008|0,0005559303|99,998651869|
|getdents64|0,000072|0,0005003373|99,9991522063|
|getppid|0,000071|0,0004933881|99,9996455944|
|epoll_create1|0,000051|0,0003544056|100|

## WebImage
| System call | Duration | Relative % on duration | Cumulative % on duration |
| --- | --- | --- | --- |
|restart_syscall|3,929376|61,2697291011|61,2697291011|
|ioctl|1,021776|15,9322851063|77,2020142075|
|epoll_pwait|0,854101|13,3177728207|90,5197870282|
|futex|0,425093|6,6283636264|97,1481506545|
|recvfrom|0,150069|2,3399865466|99,4881372011|
|write|0,006283|0,0979691707|99,5861063718|
|mmap2|0,004307|0,0671579211|99,6532642928|
|clock_gettime|0,003943|0,0614821646|99,7147464574|
|mprotect|0,00391|0,0609676042|99,7757140616|
|prctl|0,002486|0,0387635458|99,8144776074|
|getpriority|0,002358|0,0367676754|99,8512452828|
|read|0,00186|0,029002492|99,8802477748|
|clone|0,001837|0,0286438591|99,9088916339|
|sched_yield|0,001522|0,0237321467|99,9326237806|
|madvise|0,00081|0,0126301175|99,9452538981|
|getuid32|0,000768|0,0119752225|99,9572291206|
|openat|0,000568|0,008856675|99,9660857956|
|close|0,000492|0,0076716269|99,9737574225|
|munmap|0,000418|0,0065177643|99,9802751869|
|sigaltstack|0,000417|0,0065021716|99,9867773585|
|setpriority|0,000285|0,0044439302|99,9912212887|
|fchmod|0,000203|0,0031653257|99,9943866144|
|rt_sigprocmask|0,000132|0,0020582414|99,9964448558|
|set_tid_address|0,000129|0,0020114632|99,998456319|
|dup|0,000099|0,001543681|100|

# Selected system calls
Base on the results, the selected system calls are:
* epoll\_pwait()
* futex()
* ioctl()
* restart\_syscall()

Also selected:

* clock\_gettime()
* gettimeofday()
* getuid32()
* mmap2()
* mprotect()
* prctl()
* read()
* write()

# [Description of system calls](http://linux.die.net/)
## clock\_gettime()
The function clock\_gettime() retrieve the time of the specified clock.

A clock may be system-wide and hence visible for all processes, or per-process if it measures time only within a single process.

All implementations support the system-wide real-time clock, which is identified by CLOCK\_REALTIME. Its time represents seconds and nanoseconds since the Epoch. When its time is changed, timers for a relative interval are unaffected, but timers for an absolute point in time are affected.

More clocks may be implemented. The interpretation of the corresponding time values and the effect on timers is unspecified.

## clone()
clone() creates a new process, in a manner similar to fork(2). It is actually a library function layered on top of the underlying clone() system call, hereinafter referred to as sys\_clone. A description of sys\_clone is given toward the end of this page.

Unlike fork(2), these calls allow the child process to share parts of its execution context with the calling process, such as the memory space, the table of file descriptors, and the table of signal handlers. (Note that on this description, "calling process" normally corresponds to "parent process".)

The main use of clone() is to implement threads: multiple threads of control in a program that run concurrently in a shared memory space.

When the child process is created with clone(), it executes the function fn(arg). (This differs from fork(2), where execution continues in the child from the point of the fork(2) call.) The fn argument is a pointer to a function that is called by the child process at the beginning of its execution. The arg argument is passed to the fn function.

When the fn(arg) function application returns, the child process terminates. The integer returned by fn is the exit code for the child process. The child process may also terminate explicitly by calling exit(2) or after receiving a fatal signal.

The child\_stack argument specifies the location of the stack used by the child process. Since the child and calling process may share memory, it is not possible for the child process to execute in the same stack as the calling process. The calling process must therefore set up memory space for the child stack and pass a pointer to this space to clone(). Stacks grow downward on all processors that run Linux (except the HP PA processors), so child\_stack usually points to the topmost address of the memory space set up for the child stack.

The low byte of flags contains the number of the termination signal sent to the parent when the child dies. If this signal is specified as anything other than SIGCHLD, then the parent process must specify the \_\_WALL or \_\_WCLONE options when waiting for the child with wait(2). If no signal is specified, then the parent process is not signaled when the child terminates.

## epoll\_pwait()
The epoll\_wait() system call waits for events on the epoll(7) instance referred to by the file descriptor epfd. The memory area pointed to by events will contain the events that will be available for the caller. Up to maxevents are returned by epoll\_wait(). The maxevents argument must be greater than zero.

The timeout argument specifies the minimum number of milliseconds that epoll\_wait() will block. (This interval will be rounded up to the system clock granularity, and kernel scheduling delays mean that the blocking interval may overrun by a small amount.) Specifying a timeout of -1 causes epoll\_wait() to block indefinitely, while specifying a timeout equal to zero cause epoll\_wait() to return immediately, even if no events are available.

epoll\_pwait() allows an application to safely wait until either a file descriptor becomes ready or until a signal is caught.

If the sigmask argument is NULL, epoll\_pwait() is equivalent to epoll\_wait().

## futex()
The futex() system call provides a method for a program to wait for a value at a given address to change, and a method to wake up anyone waiting on a particular address (while the addresses for the same memory in separate processes may not be equal, the kernel maps them internally so the same memory mapped in different locations will correspond for futex() calls). This system call is typically used to implement the contended case of a lock in shared memory.

## gettimeofday()
The function gettimeofday() can get the time as well as a timezone in a timeval struct.

## getuid32()
getuid() returns the real user ID of the calling process.

The original Linux getuid() and geteuid() system calls supported only 16-bit user IDs. Subsequently, Linux 2.4 added getuid32() and geteuid32(), supporting 32-bit IDs.

## ioctl()
The ioctl() function manipulates the underlying device parameters of special files. In particular, many operating characteristics of character special files (e.g., terminals) may be controlled with ioctl() requests. The argument d must be an open file descriptor.

The second argument is a device-dependent request code. The third argument is an untyped pointer to memory. It's traditionally char \*argp (from the days before void \* was valid C), and will be so named for this discussion.

An ioctl() request has encoded in it whether the argument is an in parameter or out parameter, and the size of the argument argp in bytes. Macros and defines used in specifying an ioctl() request are located in the file &lt;sys/ioctl.h&gt;.

## madvise()
The madvise() system call advises the kernel about how to handle paging input/output in the address range beginning at address addr and with size length bytes. It allows an application to tell the kernel how it expects to use some mapped or shared memory areas, so that the kernel can choose appropriate read-ahead and caching techniques. This call does not influence the semantics of the application (except in the case of MADV\_DONTNEED), but may influence its performance. The kernel is free to ignore the advice.

## mmap2()
mmap() creates a new mapping in the virtual address space of the calling process. The starting address for the new mapping is specified in addr. The length argument specifies the length of the mapping.

If addr is NULL, then the kernel chooses the address at which to create the mapping; this is the most portable method of creating a new mapping. If addr is not NULL, then the kernel takes it as a hint about where to place the mapping; on Linux, the mapping will be created at a nearby page boundary. The address of the new mapping is returned as the result of the call.

## mprotect()
mprotect() changes protection for the calling process's memory page(s) containing any part of the address range in the interval [addr, addr+len-1]. addr must be aligned to a page boundary.

If the calling process tries to access memory in a manner that violates the protection, then the kernel generates a SIGSEGV signal for the process.

## munmap()
The munmap() system call deletes the mappings for the specified address range, and causes further references to addresses within the range to generate invalid memory references. The region is also automatically unmapped when the process is terminated. On the other hand, closing the file descriptor does not unmap the region.

## prctl()
The prctl() performs operations on a process.

prctl() is called with a first argument describing what to do (with values defined in &lt;linux/prctl.h&gt;), and further arguments with a significance depending on the first one.

## read()
read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.

On files that support seeking, the read operation commences at the current file offset, and the file offset is incremented by the number of bytes read. If the current file offset is at or past the end of file, no bytes are read, and read() returns zero.

If count is zero, read() may detect the errors described below. In the absence of any errors, or if read() does not check for errors, a read() with a count of 0 returns zero and has no other effects.

If count is greater than SSIZE\_MAX, the result is unspecified.

## recvfrom()
The recvfrom() call is used to receive messages from a socket, and may be used to receive data on a socket whether or not it is connection-oriented.

The routine return the length of the message on successful completion. If a message is too long to fit in the supplied buffer, excess bytes may be discarded depending on the type of socket the message is received from.

If no messages are available at the socket, the receive call wait for a message to arrive, unless the socket is nonblocking (see fcntl(2)), in which case the value -1 is returned and the external variable errno is set to EAGAIN or EWOULDBLOCK. The receive calls normally return any data available, up to the requested amount, rather than waiting for receipt of the full amount requested.

## restart\_syscall()
The restart\_syscall() system call is used to restart certain system calls after a process that was stopped by a signal (e.g., SIGSTOP or SIGTSTP) is later resumed after receiving a SIGCONT signal.  This system call is designed only for internal use by the kernel.

restart\_syscall() is used for restarting only those system calls that, when restarted, should adjust their time-related parameters—namely poll(2) (since Linux 2.6.24), nanosleep(2) (since Linux 2.6), clock\_nanosleep(2) (since Linux 2.6), and futex(2), when employed with the FUTEX\_WAIT (since Linux 2.6.22) and FUTEX\_WAIT\_BITSET (since Linux 2.6.31) operations.  restart\_syscall() restarts the interrupted system call with a time argument that is suitably adjusted to account for the time that has already elapsed (including the time where the process was stopped by a signal).  Without the restart\_syscall() mechanism, restarting these system calls would not correctly deduct the already elapsed time when the process continued execution.

There is no glibc wrapper for this system call, because it is intended for use only by the kernel and should never be called by applications.

The kernel uses restart\_syscall() to ensure that when a system call is restarted after a process has been stopped by a signal and then resumed by SIGCONT, then the time that the process spent in the stopped state is counted against the timeout interval specified in the original system call.  In the case of system calls that take a timeout argument and automatically restart after a stop signal plus SIGCONT, but which do not have the restart\_syscall(2) mechanism built in, then, after the process resumes execution, the time that the process spent in the stop state is not counted against the timeout value.  Notable examples of system calls that suffer this problem are ppoll(2), select(2), and pselect(2).

From user space, the operation of restart\_syscall() is largely invisible: to the process that made the system call that is restarted, it appears as though that system call executed and returned in the usual fashion.

## write()
write() writes up to count bytes from the buffer pointed buf to the file referred to by the file descriptor fd.

The number of bytes written may be less than count if, for example, there is insufficient space on the underlying physical medium, or the RLIMIT\_FSIZE resource limit is encountered (see setrlimit(2)), or the call was interrupted by a signal handler after having written less than count bytes. (See also pipe(7).)

For a seekable file (i.e., one to which lseek(2) may be applied, for example, a regular file) writing takes place at the current file offset, and the file offset is incremented by the number of bytes actually written. If the file was open(2)ed with O\_APPEND, the file offset is first set to the end of the file before writing. The adjustment of the file offset and the write operation are performed as an atomic step.
