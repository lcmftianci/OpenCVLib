#include <iostream>


bool Init(std::string concat, int logLevel)
{
	this->concat = concat;
	pj_log_set_level(logLevel);
	auto status = pj_init();

	status = pjlib_util_init();

	pj_caching_pool_init(&cachingPool, &pj_pool_factory_default_policy, 0);

	status = pjsip_endpt_create(&cachingPool.factory, nullptr, &endPoint);

	status = pjsip_tsx_layer_init_module(endPoint);

	status = pjsip_ua_init_module(endPoint, nullptr);

	pool = pj_pool_create(&cachingPool.factory, "proxyapp", 4000, 4000, nullptr);
	auto pjStr = StrToPjstr(GetAddr());

	pj_sockaddr_in pjAddr;
	pjAddr.sin_family = pj_AF_INET();
	pj_inet_aton(&pjStr, &pjAddr.sin_addr);

	auto port = GetPort();
	pjAddr.sin_port = pj_htons(static_cast<pj_uint16_t>(GetPort()));
	status = pjsip_udp_transport_start(endPoint, &pjAddr, nullptr, 1, nullptr);
	if (status != PJ_SUCCESS) return status;

	auto realm = StrToPjstr(GetLocalDomain());
	return pjsip_auth_srv_init(pool, &authentication, &realm, lookup, 0) == PJ_SUCCESS ? true : false;

}