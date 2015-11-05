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
  <tr>	<td>ioctl</td>	<td>798</td>	<td>1373</td>	<td>1087.30</td>	<td>0.000021</td>	<td>2.653122</td>	<td>0.022584</td>	<td>	245.563588	</td>	</tr>
  <tr>	<td>futex</td>	<td>1083</td>	<td>2043</td>	<td>1492.20</td>	<td>0.000018</td>	<td>9.997884</td>	<td>0.012485</td>	<td>	186.301315	</td>	</tr>
  <tr>	<td>restart_syscall</td>	<td>2</td>	<td>4</td>	<td>2.90</td>	<td>0.000580</td>	<td>9.397483</td>	<td>4.552083</td>	<td>	132.010407	</td>	</tr>
  <tr>	<td>epoll_pwait</td>	<td>161</td>	<td>283</td>	<td>217.10</td>	<td>0.000020</td>	<td>4.238300</td>	<td>0.059458</td>	<td>	129.084503	</td>	</tr>
  <tr>	<td>clock_gettime</td>	<td>1133</td>	<td>2760</td>	<td>2032.30</td>	<td>0.000018</td>	<td>0.171895</td>	<td>0.000144</td>	<td>	2.931320	</td>	</tr>
  <tr>	<td>pselect6</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.076822</td>	<td>0.574914</td>	<td>0.339859</td>	<td>	2.039157	</td>	</tr>
  <tr>	<td>write</td>	<td>233</td>	<td>590</td>	<td>375.40</td>	<td>0.000021</td>	<td>0.078820</td>	<td>0.000374</td>	<td>	1.404989	</td>	</tr>
  <tr>	<td>gettimeofday</td>	<td>228</td>	<td>272</td>	<td>256.90</td>	<td>0.000021</td>	<td>0.055956</td>	<td>0.000360</td>	<td>	0.925165	</td>	</tr>
  <tr>	<td>prctl</td>	<td>152</td>	<td>399</td>	<td>240.00</td>	<td>0.000018</td>	<td>0.103392</td>	<td>0.000210</td>	<td>	0.505497	</td>	</tr>
  <tr>	<td>getuid32</td>	<td>97</td>	<td>177</td>	<td>146.00</td>	<td>0.000019</td>	<td>0.029453</td>	<td>0.000278</td>	<td>	0.406434	</td>	</tr>
  <tr>	<td>recvfrom</td>	<td>114</td>	<td>269</td>	<td>193.40</td>	<td>0.000022</td>	<td>0.099773</td>	<td>0.000151</td>	<td>	0.293252	</td>	</tr>
  <tr>	<td>fcntl64</td>	<td>56</td>	<td>94</td>	<td>78.60</td>	<td>0.000029</td>	<td>0.010029</td>	<td>0.000345</td>	<td>	0.271836	</td>	</tr>
  <tr>	<td>madvise</td>	<td>131</td>	<td>299</td>	<td>249.80</td>	<td>0.000024</td>	<td>0.010951</td>	<td>0.000096</td>	<td>	0.240590	</td>	</tr>
  <tr>	<td>close</td>	<td>192</td>	<td>385</td>	<td>287.40</td>	<td>0.000021</td>	<td>0.014263</td>	<td>0.000072</td>	<td>	0.207160	</td>	</tr>
  <tr>	<td>read</td>	<td>88</td>	<td>211</td>	<td>151.30</td>	<td>0.000022</td>	<td>0.030345</td>	<td>0.000132</td>	<td>	0.200252	</td>	</tr>
  <tr>	<td>mmap2</td>	<td>35</td>	<td>66</td>	<td>56.10</td>	<td>0.000026</td>	<td>0.004830</td>	<td>0.000242</td>	<td>	0.136210	</td>	</tr>
  <tr>	<td>munmap</td>	<td>32</td>	<td>63</td>	<td>51.10</td>	<td>0.000025</td>	<td>0.006052</td>	<td>0.000249</td>	<td>	0.127735	</td>	</tr>
  <tr>	<td>fdatasync</td>	<td>1</td>	<td>3</td>	<td>1.20</td>	<td>0.000363</td>	<td>0.015527</td>	<td>0.009905</td>	<td>	0.118866	</td>	</tr>
  <tr>	<td>getpriority</td>	<td>55</td>	<td>101</td>	<td>79.20</td>	<td>0.000018</td>	<td>0.008639</td>	<td>0.000143</td>	<td>	0.113582	</td>	</tr>
  <tr>	<td>pread</td>	<td>23</td>	<td>57</td>	<td>40.20</td>	<td>0.000029</td>	<td>0.006150</td>	<td>0.000234</td>	<td>	0.094389	</td>	</tr>
  <tr>	<td>fsync</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.006513</td>	<td>0.013021</td>	<td>0.009062</td>	<td>	0.090625	</td>	</tr>
  <tr>	<td>clone</td>	<td>2</td>	<td>9</td>	<td>5.60</td>	<td>0.000074</td>	<td>0.026230</td>	<td>0.001610</td>	<td>	0.090203	</td>	</tr>
  <tr>	<td>openat</td>	<td>26</td>	<td>44</td>	<td>37.60</td>	<td>0.000037</td>	<td>0.005287</td>	<td>0.000235</td>	<td>	0.088473	</td>	</tr>
  <tr>	<td>sched_yield</td>	<td>14</td>	<td>208</td>	<td>129.60</td>	<td>0.000018</td>	<td>0.002601</td>	<td>0.000063</td>	<td>	0.082477	</td>	</tr>
  <tr>	<td>dup</td>	<td>88</td>	<td>202</td>	<td>146.70</td>	<td>0.000019</td>	<td>0.005177</td>	<td>0.000049</td>	<td>	0.072857	</td>	</tr>
  <tr>	<td>fstat64</td>	<td>8</td>	<td>32</td>	<td>24.80</td>	<td>0.000026</td>	<td>0.007958</td>	<td>0.000270</td>	<td>	0.066965	</td>	</tr>
  <tr>	<td>newfstatat</td>	<td>4</td>	<td>16</td>	<td>13.20</td>	<td>0.000036</td>	<td>0.011845</td>	<td>0.000406</td>	<td>	0.053600	</td>	</tr>
  <tr>	<td>mprotect</td>	<td>10</td>	<td>37</td>	<td>23.50</td>	<td>0.000021</td>	<td>0.021022</td>	<td>0.000211</td>	<td>	0.049731	</td>	</tr>
  <tr>	<td>pwrite</td>	<td>20</td>	<td>31</td>	<td>21.10</td>	<td>0.000059</td>	<td>0.007197</td>	<td>0.000233</td>	<td>	0.049237	</td>	</tr>
  <tr>	<td>writev</td>	<td>8</td>	<td>14</td>	<td>12.00</td>	<td>0.000042</td>	<td>0.007569</td>	<td>0.000335</td>	<td>	0.040223	</td>	</tr>
  <tr>	<td>setpriority</td>	<td>8</td>	<td>19</td>	<td>16.10</td>	<td>0.000021</td>	<td>0.012566</td>	<td>0.000228</td>	<td>	0.036824	</td>	</tr>
  <tr>	<td>faccessat</td>	<td>8</td>	<td>16</td>	<td>13.30</td>	<td>0.000037</td>	<td>0.005297</td>	<td>0.000253</td>	<td>	0.033780	</td>	</tr>
  <tr>	<td>rt_sigprocmask</td>	<td>25</td>	<td>42</td>	<td>40.20</td>	<td>0.000020</td>	<td>0.000779</td>	<td>0.000053</td>	<td>	0.021641	</td>	</tr>
  <tr>	<td>nanosleep</td>	<td>1</td>	<td>3</td>	<td>1.40</td>	<td>0.001600</td>	<td>0.003104</td>	<td>0.001832</td>	<td>	0.012830	</td>	</tr>
  <tr>	<td>sigaltstack</td>	<td>5</td>	<td>13</td>	<td>9.40</td>	<td>0.000020</td>	<td>0.001716</td>	<td>0.000136</td>	<td>	0.012808	</td>	</tr>
  <tr>	<td>geteuid32</td>	<td>1</td>	<td>5</td>	<td>3.80</td>	<td>0.000034</td>	<td>0.000617</td>	<td>0.000148</td>	<td>	0.005649	</td>	</tr>
  <tr>	<td>set_tid_address</td>	<td>3</td>	<td>4</td>	<td>3.80</td>	<td>0.000019</td>	<td>0.000236</td>	<td>0.000097</td>	<td>	0.003716	</td>	</tr>
  <tr>	<td>unlinkat</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000146</td>	<td>0.000380</td>	<td>0.000244</td>	<td>	0.002446	</td>	</tr>
  <tr>	<td>renameat</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000094</td>	<td>0.000406</td>	<td>0.000192</td>	<td>	0.001921	</td>	</tr>
  <tr>	<td>getsockopt</td>	<td>1</td>	<td>3</td>	<td>2.00</td>	<td>0.000024</td>	<td>0.000232</td>	<td>0.000093</td>	<td>	0.001875	</td>	</tr>
  <tr>	<td>fchmodat</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000053</td>	<td>0.000273</td>	<td>0.000139</td>	<td>	0.001394	</td>	</tr>
  <tr>	<td>epoll_ctl</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000027</td>	<td>0.000168</td>	<td>0.000083</td>	<td>	0.000748	</td>	</tr>
  <tr>	<td>eventfd2</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000024</td>	<td>0.000132</td>	<td>0.000056</td>	<td>	0.000512	</td>	</tr>
  <tr>	<td>epoll_create1</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000024</td>	<td>0.000131</td>	<td>0.000056</td>	<td>	0.000510	</td>	</tr>
  <tr>	<td>ftruncate64</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000109</td>	<td>0.000109</td>	<td>0.000109</td>	<td>	0.000109	</td>	</tr>
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
  <tr>	<td>ioctl</td>	<td>2</td>	<td>5</td>	<td>3.80</td>	<td>0.000020</td>	<td>0.548940</td>	<td>0.243317</td>	<td>	9.246053	</td>	</tr>
  <tr>	<td>epoll_pwait</td>	<td>3</td>	<td>3</td>	<td>3.00</td>	<td>0.000021</td>	<td>0.602746</td>	<td>0.168716</td>	<td>	5.061495	</td>	</tr>
  <tr>	<td>write</td>	<td>5</td>	<td>8</td>	<td>6.80</td>	<td>0.000024</td>	<td>0.015051</td>	<td>0.001007</td>	<td>	0.068510	</td>	</tr>
  <tr>	<td>futex</td>	<td>4</td>	<td>13</td>	<td>7.60</td>	<td>0.000020</td>	<td>0.011290</td>	<td>0.000531</td>	<td>	0.040388	</td>	</tr>
  <tr>	<td>read</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000022</td>	<td>0.034426</td>	<td>0.003663</td>	<td>	0.036635	</td>	</tr>
  <tr>	<td>prctl</td>	<td>4</td>	<td>10</td>	<td>7.60</td>	<td>0.000021</td>	<td>0.003480</td>	<td>0.000135</td>	<td>	0.010318	</td>	</tr>
  <tr>	<td>clock_gettime</td>	<td>6</td>	<td>6</td>	<td>6.00</td>	<td>0.000020</td>	<td>0.002519</td>	<td>0.000138</td>	<td>	0.008316	</td>	</tr>
  <tr>	<td>mmap2</td>	<td>3</td>	<td>3</td>	<td>3.00</td>	<td>0.000028</td>	<td>0.003860</td>	<td>0.000412</td>	<td>	0.007424	</td>	</tr>
  <tr>	<td>mprotect</td>	<td>4</td>	<td>4</td>	<td>4.00</td>	<td>0.000021</td>	<td>0.000848</td>	<td>0.000141</td>	<td>	0.003398	</td>	</tr>
  <tr>	<td>getpriority</td>	<td>2</td>	<td>3</td>	<td>2.60</td>	<td>0.000020</td>	<td>0.000599</td>	<td>0.000128</td>	<td>	0.003346	</td>	</tr>
  <tr>	<td>clone</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000080</td>	<td>0.000542</td>	<td>0.000377</td>	<td>	0.002264	</td>	</tr>
  <tr>	<td>sigaltstack</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000026</td>	<td>0.001281</td>	<td>0.000290</td>	<td>	0.001743	</td>	</tr>
  <tr>	<td>getuid32</td>	<td>2</td>	<td>3</td>	<td>2.60</td>	<td>0.000019</td>	<td>0.000237</td>	<td>0.000051</td>	<td>	0.001349	</td>	</tr>
  <tr>	<td>madvise</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000039</td>	<td>0.000201</td>	<td>0.000070</td>	<td>	0.000424	</td>	</tr>
  <tr>	<td>setpriority</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000028</td>	<td>0.000139</td>	<td>0.000062</td>	<td>	0.000374	</td>	</tr>
  <tr>	<td>openat</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000043</td>	<td>0.000060</td>	<td>0.000052</td>	<td>	0.000316	</td>	</tr>
  <tr>	<td>close</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000024</td>	<td>0.000032</td>	<td>0.000029</td>	<td>	0.000176	</td>	</tr>
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
  <tr>	<td>restart_syscall</td>	<td>1</td>	<td>2</td>	<td>1.40</td>	<td>0.047498</td>	<td>9.881570</td>	<td>4.910087</td>	<td>	68.741230	</td>	</tr>
  <tr>	<td>futex</td>	<td>51</td>	<td>170</td>	<td>99.70</td>	<td>0.000019</td>	<td>9.998640</td>	<td>0.063135</td>	<td>	62.946175	</td>	</tr>
  <tr>	<td>ioctl</td>	<td>108</td>	<td>155</td>	<td>144.30</td>	<td>0.000020</td>	<td>0.480710</td>	<td>0.007021</td>	<td>	10.132316	</td>	</tr>
  <tr>	<td>epoll_pwait</td>	<td>23</td>	<td>30</td>	<td>28.40</td>	<td>0.000021</td>	<td>0.073338</td>	<td>0.004967</td>	<td>	1.410772	</td>	</tr>
  <tr>	<td>mprotect</td>	<td>180</td>	<td>235</td>	<td>223.80</td>	<td>0.000021</td>	<td>0.002245</td>	<td>0.000039</td>	<td>	0.087587	</td>	</tr>
  <tr>	<td>madvise</td>	<td>46</td>	<td>56</td>	<td>50.00</td>	<td>0.000024</td>	<td>0.004157</td>	<td>0.000166</td>	<td>	0.083015	</td>	</tr>
  <tr>	<td>mmap2</td>	<td>62</td>	<td>104</td>	<td>87.20</td>	<td>0.000022</td>	<td>0.002545</td>	<td>0.000094</td>	<td>	0.082720	</td>	</tr>
  <tr>	<td>clock_gettime</td>	<td>72</td>	<td>217</td>	<td>133.30</td>	<td>0.000019</td>	<td>0.002375</td>	<td>0.000057</td>	<td>	0.076965	</td>	</tr>
  <tr>	<td>write</td>	<td>28</td>	<td>38</td>	<td>34.20</td>	<td>0.000023</td>	<td>0.001462</td>	<td>0.000178</td>	<td>	0.061143	</td>	</tr>
  <tr>	<td>openat</td>	<td>36</td>	<td>89</td>	<td>77.70</td>	<td>0.000025</td>	<td>0.001302</td>	<td>0.000054</td>	<td>	0.042557	</td>	</tr>
  <tr>	<td>getuid32</td>	<td>16</td>	<td>19</td>	<td>17.60</td>	<td>0.000019</td>	<td>0.026055</td>	<td>0.000236</td>	<td>	0.041578	</td>	</tr>
  <tr>	<td>prctl</td>	<td>27</td>	<td>50</td>	<td>39.30</td>	<td>0.000021</td>	<td>0.003043</td>	<td>0.000099</td>	<td>	0.039293	</td>	</tr>
  <tr>	<td>munmap</td>	<td>6</td>	<td>35</td>	<td>19.00</td>	<td>0.000025</td>	<td>0.010198</td>	<td>0.000146</td>	<td>	0.027761	</td>	</tr>
  <tr>	<td>clone</td>	<td>2</td>	<td>4</td>	<td>2.80</td>	<td>0.000091</td>	<td>0.001787</td>	<td>0.000916</td>	<td>	0.025663	</td>	</tr>
  <tr>	<td>close</td>	<td>24</td>	<td>59</td>	<td>51.40</td>	<td>0.000019</td>	<td>0.000756</td>	<td>0.000036</td>	<td>	0.018603	</td>	</tr>
  <tr>	<td>rt_sigprocmask</td>	<td>33</td>	<td>37</td>	<td>36.20</td>	<td>0.000020</td>	<td>0.000356</td>	<td>0.000029</td>	<td>	0.010750	</td>	</tr>
  <tr>	<td>getpriority</td>	<td>9</td>	<td>11</td>	<td>9.80</td>	<td>0.000019</td>	<td>0.001690</td>	<td>0.000108</td>	<td>	0.010641	</td>	</tr>
  <tr>	<td>fstat64</td>	<td>14</td>	<td>39</td>	<td>34.00</td>	<td>0.000020</td>	<td>0.001248</td>	<td>0.000031</td>	<td>	0.010549	</td>	</tr>
  <tr>	<td>faccessat</td>	<td>6</td>	<td>12</td>	<td>10.80</td>	<td>0.000026</td>	<td>0.001382</td>	<td>0.000096</td>	<td>	0.010389	</td>	</tr>
  <tr>	<td>read</td>	<td>10</td>	<td>16</td>	<td>14.90</td>	<td>0.000020</td>	<td>0.000524</td>	<td>0.000064</td>	<td>	0.009544	</td>	</tr>
  <tr>	<td>pread</td>	<td>3</td>	<td>8</td>	<td>7.00</td>	<td>0.000024</td>	<td>0.002260</td>	<td>0.000101</td>	<td>	0.007072	</td>	</tr>
  <tr>	<td>writev</td>	<td>4</td>	<td>7</td>	<td>5.90</td>	<td>0.000031</td>	<td>0.000364</td>	<td>0.000086</td>	<td>	0.005075	</td>	</tr>
  <tr>	<td>setpriority</td>	<td>2</td>	<td>5</td>	<td>3.60</td>	<td>0.000027</td>	<td>0.000491</td>	<td>0.000115</td>	<td>	0.004146	</td>	</tr>
  <tr>	<td>sigaltstack</td>	<td>2</td>	<td>4</td>	<td>2.80</td>	<td>0.000026</td>	<td>0.000411</td>	<td>0.000139</td>	<td>	0.003915	</td>	</tr>
  <tr>	<td>dup</td>	<td>5</td>	<td>11</td>	<td>10.00</td>	<td>0.000019</td>	<td>0.000161</td>	<td>0.000034</td>	<td>	0.003415	</td>	</tr>
  <tr>	<td>recvfrom</td>	<td>7</td>	<td>8</td>	<td>7.90</td>	<td>0.000024</td>	<td>0.000121</td>	<td>0.000036</td>	<td>	0.002899	</td>	</tr>
  <tr>	<td>socket</td>	<td>2</td>	<td>2</td>	<td>2.00</td>	<td>0.000036</td>	<td>0.000276</td>	<td>0.000107</td>	<td>	0.002157	</td>	</tr>
  <tr>	<td>fcntl64</td>	<td>4</td>	<td>4</td>	<td>4.00</td>	<td>0.000020</td>	<td>0.000247</td>	<td>0.000050</td>	<td>	0.002039	</td>	</tr>
  <tr>	<td>readlinkat</td>	<td>1</td>	<td>4</td>	<td>3.40</td>	<td>0.000037</td>	<td>0.000100</td>	<td>0.000059</td>	<td>	0.002006	</td>	</tr>
  <tr>	<td>epoll_ctl</td>	<td>1</td>	<td>4</td>	<td>3.40</td>	<td>0.000025</td>	<td>0.000425</td>	<td>0.000050</td>	<td>	0.001713	</td>	</tr>
  <tr>	<td>connect</td>	<td>2</td>	<td>2</td>	<td>2.00</td>	<td>0.000029</td>	<td>0.000147</td>	<td>0.000063</td>	<td>	0.001265	</td>	</tr>
  <tr>	<td>getsockopt</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000021</td>	<td>0.000322</td>	<td>0.000111</td>	<td>	0.000891	</td>	</tr>
  <tr>	<td>getdents64</td>	<td>2</td>	<td>2</td>	<td>2.00</td>	<td>0.000022</td>	<td>0.000090</td>	<td>0.000036</td>	<td>	0.000728	</td>	</tr>
  <tr>	<td>eventfd2</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000026</td>	<td>0.000294</td>	<td>0.000080</td>	<td>	0.000646	</td>	</tr>
  <tr>	<td>getppid</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000021</td>	<td>0.000206</td>	<td>0.000071</td>	<td>	0.000569	</td>	</tr>
  <tr>	<td>epoll_create1</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000025</td>	<td>0.000186</td>	<td>0.000051</td>	<td>	0.000414	</td>	</tr>
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
  <tr>	<td>ioctl</td>	<td>20</td>	<td>27</td>	<td>24.00</td>	<td>0.000020</td>	<td>0.548304</td>	<td>0.042574</td>	<td>	10.217859	</td>	</tr>
  <tr>	<td>epoll_pwait</td>	<td>8</td>	<td>9</td>	<td>8.80</td>	<td>0.000022</td>	<td>0.859483</td>	<td>0.097057</td>	<td>	8.541099	</td>	</tr>
  <tr>	<td>futex</td>	<td>17</td>	<td>37</td>	<td>25.10</td>	<td>0.000020</td>	<td>0.895571</td>	<td>0.016936</td>	<td>	4.251185	</td>	</tr>
  <tr>	<td>restart_syscall</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>3.929376</td>	<td>3.929376</td>	<td>3.929376</td>	<td>	3.929376	</td>	</tr>
  <tr>	<td>recvfrom</td>	<td>199</td>	<td>422</td>	<td>249.70</td>	<td>0.000024</td>	<td>0.103927</td>	<td>0.000601</td>	<td>	1.501590	</td>	</tr>
  <tr>	<td>write</td>	<td>13</td>	<td>19</td>	<td>16.80</td>	<td>0.000023</td>	<td>0.011084</td>	<td>0.000374</td>	<td>	0.062945	</td>	</tr>
  <tr>	<td>mmap2</td>	<td>8</td>	<td>14</td>	<td>11.80</td>	<td>0.000029</td>	<td>0.007088</td>	<td>0.000365</td>	<td>	0.043177	</td>	</tr>
  <tr>	<td>clock_gettime</td>	<td>34</td>	<td>36</td>	<td>34.90</td>	<td>0.000020</td>	<td>0.008010</td>	<td>0.000113</td>	<td>	0.039554	</td>	</tr>
  <tr>	<td>mprotect</td>	<td>4</td>	<td>12</td>	<td>9.20</td>	<td>0.000021</td>	<td>0.021291</td>	<td>0.000425</td>	<td>	0.039165	</td>	</tr>
  <tr>	<td>prctl</td>	<td>9</td>	<td>21</td>	<td>16.80</td>	<td>0.000021</td>	<td>0.005630</td>	<td>0.000148</td>	<td>	0.024913	</td>	</tr>
  <tr>	<td>getpriority</td>	<td>4</td>	<td>6</td>	<td>5.30</td>	<td>0.000019</td>	<td>0.017355</td>	<td>0.000445</td>	<td>	0.023635	</td>	</tr>
  <tr>	<td>read</td>	<td>5</td>	<td>5</td>	<td>5.00</td>	<td>0.000021</td>	<td>0.008162</td>	<td>0.000372</td>	<td>	0.018642	</td>	</tr>
  <tr>	<td>clone</td>	<td>1</td>	<td>3</td>	<td>2.30</td>	<td>0.000057</td>	<td>0.001795</td>	<td>0.000799</td>	<td>	0.018389	</td>	</tr>
  <tr>	<td>madvise</td>	<td>2</td>	<td>6</td>	<td>3.60</td>	<td>0.000035</td>	<td>0.003488</td>	<td>0.000225</td>	<td>	0.008121	</td>	</tr>
  <tr>	<td>getuid32</td>	<td>5</td>	<td>7</td>	<td>6.30</td>	<td>0.000019</td>	<td>0.001494</td>	<td>0.000122</td>	<td>	0.007732	</td>	</tr>
  <tr>	<td>openat</td>	<td>1</td>	<td>3</td>	<td>2.40</td>	<td>0.000036</td>	<td>0.001884</td>	<td>0.000237</td>	<td>	0.005708	</td>	</tr>
  <tr>	<td>close</td>	<td>5</td>	<td>7</td>	<td>6.40</td>	<td>0.000020</td>	<td>0.001957</td>	<td>0.000077</td>	<td>	0.004985	</td>	</tr>
  <tr>	<td>sigaltstack</td>	<td>1</td>	<td>3</td>	<td>2.40</td>	<td>0.000020</td>	<td>0.001720</td>	<td>0.000174</td>	<td>	0.004188	</td>	</tr>
  <tr>	<td>sched_yield</td>	<td>37</td>	<td>50</td>	<td>43.50</td>	<td>0.000022</td>	<td>0.000791</td>	<td>0.000035</td>	<td>	0.003065	</td>	</tr>
  <tr>	<td>setpriority</td>	<td>1</td>	<td>3</td>	<td>2.30</td>	<td>0.000022</td>	<td>0.000435</td>	<td>0.000124</td>	<td>	0.002864	</td>	</tr>
  <tr>	<td>dup</td>	<td>3</td>	<td>3</td>	<td>3.00</td>	<td>0.000020</td>	<td>0.000059</td>	<td>0.000033</td>	<td>	0.001015	</td>	</tr>
  <tr>	<td>munmap</td>	<td>2</td>	<td>2</td>	<td>2.00</td>	<td>0.000209</td>	<td>0.000210</td>	<td>0.000209</td>	<td>	0.000419	</td>	</tr>
  <tr>	<td>fchmod</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000203</td>	<td>0.000203</td>	<td>0.000203</td>	<td>	0.000203	</td>	</tr>
  <tr>	<td>rt_sigprocmask</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000132</td>	<td>0.000132</td>	<td>0.000132</td>	<td>	0.000132	</td>	</tr>
  <tr>	<td>set_tid_address</td>	<td>1</td>	<td>1</td>	<td>1.00</td>	<td>0.000129</td>	<td>0.000129</td>	<td>0.000129</td>	<td>	0.000129	</td>	</tr>
</table>

# Common system calls
## Frequency (alphabetical order)
* **clock_gettime**
* **epoll_pwait**
* **futex**
* **getuid32**
* **ioctl**
* **prctl**
* **write**

## Length (alphabetical order)
* **clock_gettime**
* **clone**
* **epoll_pwait**
* **futex**
* **getuid32**
* **ioctl**
* **mprotect**
* **prctl**
* **read**
* **write**

# [Description of system calls](http://linux.die.net/)
## clock_gettime()
The function clock_gettime() retrieve the time of the specified clock.

A clock may be system-wide and hence visible for all processes, or per-process if it measures time only within a single process.

All implementations support the system-wide real-time clock, which is identified by CLOCK_REALTIME. Its time represents seconds and nanoseconds since the Epoch. When its time is changed, timers for a relative interval are unaffected, but timers for an absolute point in time are affected.

More clocks may be implemented. The interpretation of the corresponding time values and the effect on timers is unspecified.

## clone()
clone() creates a new process, in a manner similar to fork(2). It is actually a library function layered on top of the underlying clone() system call, hereinafter referred to as sys_clone. A description of sys_clone is given toward the end of this page.

Unlike fork(2), these calls allow the child process to share parts of its execution context with the calling process, such as the memory space, the table of file descriptors, and the table of signal handlers. (Note that on this description, "calling process" normally corresponds to "parent process".)

The main use of clone() is to implement threads: multiple threads of control in a program that run concurrently in a shared memory space.

When the child process is created with clone(), it executes the function fn(arg). (This differs from fork(2), where execution continues in the child from the point of the fork(2) call.) The fn argument is a pointer to a function that is called by the child process at the beginning of its execution. The arg argument is passed to the fn function.

When the fn(arg) function application returns, the child process terminates. The integer returned by fn is the exit code for the child process. The child process may also terminate explicitly by calling exit(2) or after receiving a fatal signal.

The child_stack argument specifies the location of the stack used by the child process. Since the child and calling process may share memory, it is not possible for the child process to execute in the same stack as the calling process. The calling process must therefore set up memory space for the child stack and pass a pointer to this space to clone(). Stacks grow downward on all processors that run Linux (except the HP PA processors), so child_stack usually points to the topmost address of the memory space set up for the child stack.

The low byte of flags contains the number of the termination signal sent to the parent when the child dies. If this signal is specified as anything other than SIGCHLD, then the parent process must specify the \_\_WALL or \_\_WCLONE options when waiting for the child with wait(2). If no signal is specified, then the parent process is not signaled when the child terminates.

## epoll_pwait()
The epoll_wait() system call waits for events on the epoll(7) instance referred to by the file descriptor epfd. The memory area pointed to by events will contain the events that will be available for the caller. Up to maxevents are returned by epoll_wait(). The maxevents argument must be greater than zero.

The timeout argument specifies the minimum number of milliseconds that epoll_wait() will block. (This interval will be rounded up to the system clock granularity, and kernel scheduling delays mean that the blocking interval may overrun by a small amount.) Specifying a timeout of -1 causes epoll_wait() to block indefinitely, while specifying a timeout equal to zero cause epoll_wait() to return immediately, even if no events are available.

epoll_pwait() allows an application to safely wait until either a file descriptor becomes ready or until a signal is caught.

If the sigmask argument is NULL, epoll_pwait() is equivalent to epoll_wait().

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
The madvise() system call advises the kernel about how to handle paging input/output in the address range beginning at address addr and with size length bytes. It allows an application to tell the kernel how it expects to use some mapped or shared memory areas, so that the kernel can choose appropriate read-ahead and caching techniques. This call does not influence the semantics of the application (except in the case of MADV_DONTNEED), but may influence its performance. The kernel is free to ignore the advice.

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

If count is greater than SSIZE_MAX, the result is unspecified.

## recvfrom()
The recvfrom() call is used to receive messages from a socket, and may be used to receive data on a socket whether or not it is connection-oriented.

The routine return the length of the message on successful completion. If a message is too long to fit in the supplied buffer, excess bytes may be discarded depending on the type of socket the message is received from.

If no messages are available at the socket, the receive call wait for a message to arrive, unless the socket is nonblocking (see fcntl(2)), in which case the value -1 is returned and the external variable errno is set to EAGAIN or EWOULDBLOCK. The receive calls normally return any data available, up to the requested amount, rather than waiting for receipt of the full amount requested.

## restart_syscall()
The restart_syscall() system call is used to restart certain system calls after a process that was stopped by a signal (e.g., SIGSTOP or SIGTSTP) is later resumed after receiving a SIGCONT signal.  This system call is designed only for internal use by the kernel.

restart_syscall() is used for restarting only those system calls that, when restarted, should adjust their time-related parameters—namely poll(2) (since Linux 2.6.24), nanosleep(2) (since Linux 2.6), clock_nanosleep(2) (since Linux 2.6), and futex(2), when employed with the FUTEX_WAIT (since Linux 2.6.22) and FUTEX_WAIT_BITSET (since Linux 2.6.31) operations.  restart_syscall() restarts the interrupted system call with a time argument that is suitably adjusted to account for the time that has already elapsed (including the time where the process was stopped by a signal).  Without the restart_syscall() mechanism, restarting these system calls would not correctly deduct the already elapsed time when the process continued execution.

There is no glibc wrapper for this system call, because it is intended for use only by the kernel and should never be called by applications.

The kernel uses restart_syscall() to ensure that when a system call is restarted after a process has been stopped by a signal and then resumed by SIGCONT, then the time that the process spent in the stopped state is counted against the timeout interval specified in the original system call.  In the case of system calls that take a timeout argument and automatically restart after a stop signal plus SIGCONT, but which do not have the restart_syscall(2) mechanism built in, then, after the process resumes execution, the time that the process spent in the stop state is not counted against the timeout value.  Notable examples of system calls that suffer this problem are ppoll(2), select(2), and pselect(2).

From user space, the operation of restart_syscall() is largely invisible: to the process that made the system call that is restarted, it appears as though that system call executed and returned in the usual fashion.

## write()
write() writes up to count bytes from the buffer pointed buf to the file referred to by the file descriptor fd.

The number of bytes written may be less than count if, for example, there is insufficient space on the underlying physical medium, or the RLIMIT_FSIZE resource limit is encountered (see setrlimit(2)), or the call was interrupted by a signal handler after having written less than count bytes. (See also pipe(7).)

For a seekable file (i.e., one to which lseek(2) may be applied, for example, a regular file) writing takes place at the current file offset, and the file offset is incremented by the number of bytes actually written. If the file was open(2)ed with O_APPEND, the file offset is first set to the end of the file before writing. The adjustment of the file offset and the write operation are performed as an atomic step.
